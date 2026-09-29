/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by mancorte          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	N_OPS
};

enum e_loc
{
	L_TA,
	L_BA,
	L_TB,
	L_BB
};

enum e_strat
{
	ST_ADAPTIVE,
	ST_SIMPLE,
	ST_MEDIUM,
	ST_COMPLEX
};

typedef struct s_stack
{
	int	*v;
	int	head;
	int	size;
	int	cap;
}		t_stack;

typedef struct s_ps
{
	t_stack			a;
	t_stack			b;
	unsigned char	*ops;
	int				nops;
	int				cap_ops;
	const char		*name;
	const char		*cplx;
}					t_ps;

typedef struct s_opts
{
	int	strat;
	int	bench;
}		t_opts;

typedef struct s_dis
{
	long	mistakes;
	long	total;
}			t_dis;

/* stack.c / stack_ops.c */
int			st_init(t_stack *s, int cap);
void		st_free(t_stack *s);
int			st_at(t_stack *s, int i);
void		st_push(t_stack *s, int x);
int			st_pop(t_stack *s);
void		st_swap(t_stack *s);
void		st_rot(t_stack *s);
void		st_rrot(t_stack *s);

/* ops.c */
int			ps_init(t_ps *p, int *rank, int n);
void		ps_free(t_ps *p);
void		ps_apply(t_ps *p, int op);
void		ps_do(t_ps *p, int op);
const char	*op_name(int op);

/* optimize.c */
void		optimize(t_ps *p);

/* output.c */
void		print_ops(t_ps *p);
void		print_bench(t_ps *p, t_dis *d);

/* disorder.c */
t_dis		disorder(int *v, int n);
int			*to_ranks(int *v, int n);

/* parse.c */
int			parse_args(int argc, char **argv, t_opts *o, int **vals);
int			parse_int(const char *s, int *out);
int			has_dup(int *v, int n);
size_t		count_cap(int argc, char **argv);

/* algo_utils.c */
int			is_sorted(t_stack *s);
int			st_min_idx(t_stack *s);
int			st_max_idx(t_stack *s);
void		bring(t_ps *p, t_stack *s, int idx);
int			isqrt(int n);

/* chunk_utils.c */
int			dest_of(int loc, int piece);
int			chunk_peek(t_ps *p, int loc);
void		chunk_take(t_ps *p, int loc, int dest);

/* algorithms */
void		sort_simple(t_ps *p);
void		sort_medium(t_ps *p);
void		sort_complex(t_ps *p);
void		sort_low(t_ps *p);
void		lis_fill(t_stack *a, int *len, int *prv);
int			lis_mark(t_stack *a, int *len, int *prv, int *keep);
int			target_idx(t_stack *a, int x);
void		sort_small(t_ps *p);
void		sort_adaptive(t_ps *p, t_dis *d);

#endif
