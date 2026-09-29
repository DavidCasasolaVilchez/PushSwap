/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by mancorte          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_pct(t_dis *d)
{
	long	x;

	x = 0;
	if (d->total > 0)
		x = d->mistakes * 10000 / d->total;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(x / 100, 2);
	ft_putchar_fd('.', 2);
	if (x % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(x % 100, 2);
	ft_putendl_fd("%", 2);
}

static void	count_ops(t_ps *p, int *cnt)
{
	int	i;

	i = 0;
	while (i < N_OPS)
	{
		cnt[i] = 0;
		i++;
	}
	i = 0;
	while (i < p->nops)
	{
		cnt[p->ops[i]]++;
		i++;
	}
}

static void	put_counts(t_ps *p)
{
	int	cnt[N_OPS];
	int	i;

	count_ops(p, cnt);
	ft_putstr_fd("[bench] ", 2);
	i = 0;
	while (i < N_OPS)
	{
		ft_putstr_fd((char *)op_name(i), 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(cnt[i], 2);
		i++;
		if (i < N_OPS)
			ft_putstr_fd("  ", 2);
	}
	ft_putchar_fd('\n', 2);
}

static void	put_strategy(t_ps *p)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd((char *)p->name, 2);
	ft_putstr_fd(" / ", 2);
	ft_putendl_fd((char *)p->cplx, 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(p->nops, 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_ps *p, t_dis *d)
{
	put_pct(d);
	put_strategy(p);
	put_counts(p);
}
