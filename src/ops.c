/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by mancorte          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_init(t_ps *p, int *rank, int n)
{
	int	i;

	p->ops = malloc(1024);
	p->nops = 0;
	p->cap_ops = 1024;
	p->name = "";
	p->cplx = "";
	if (!p->ops || !st_init(&p->a, n) || !st_init(&p->b, n))
		return (0);
	i = 0;
	while (i < n)
	{
		p->a.v[i] = rank[i];
		i++;
	}
	p->a.size = n;
	return (1);
}

void	ps_free(t_ps *p)
{
	free(p->ops);
	st_free(&p->a);
	st_free(&p->b);
}

void	ps_apply(t_ps *p, int op)
{
	if (op == SA || op == SS)
		st_swap(&p->a);
	if (op == SB || op == SS)
		st_swap(&p->b);
	if (op == PA && p->b.size > 0)
		st_push(&p->a, st_pop(&p->b));
	if (op == PB && p->a.size > 0)
		st_push(&p->b, st_pop(&p->a));
	if (op == RA || op == RR)
		st_rot(&p->a);
	if (op == RB || op == RR)
		st_rot(&p->b);
	if (op == RRA || op == RRR)
		st_rrot(&p->a);
	if (op == RRB || op == RRR)
		st_rrot(&p->b);
}

static int	grow(t_ps *p)
{
	unsigned char	*bigger;

	bigger = malloc(p->cap_ops * 2);
	if (!bigger)
		return (0);
	ft_memcpy(bigger, p->ops, p->nops);
	free(p->ops);
	p->ops = bigger;
	p->cap_ops *= 2;
	return (1);
}

void	ps_do(t_ps *p, int op)
{
	if (p->nops == p->cap_ops && !grow(p))
	{
		ps_free(p);
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	ps_apply(p, op);
	p->ops[p->nops++] = op;
}
