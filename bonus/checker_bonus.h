/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by mancorte          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define CK_NOPS 11

typedef struct s_ck
{
	int	*a;
	int	*b;
	int	na;
	int	nb;
}		t_ck;

/* checker_parse_bonus.c */
int		ck_parse_int(const char *s, int *out);
int		ck_parse(int argc, char **argv, int **vals);

/* checker_read_bonus.c */
int		ck_op_code(const char *line);
int		ck_read_ops(unsigned char **codes, int *count);

/* checker_ops_bonus.c */
void	ck_exec(t_ck *c, int code);
int		ck_sorted(t_ck *c);

#endif
