/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by jucortes          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_strategy(t_ps *p, t_opts *o, t_dis *d)
{
	if (o->strat == ST_SIMPLE)
		sort_simple(p);
	else if (o->strat == ST_MEDIUM)
		sort_medium(p);
	else if (o->strat == ST_COMPLEX)
		sort_complex(p);
	else
		sort_adaptive(p, d);
}

static int	solve(int *vals, int n, t_opts *o)
{
	t_ps	p;
	t_dis	d;
	int		*rank;

	d = disorder(vals, n);
	rank = to_ranks(vals, n);
	if (!rank || !ps_init(&p, rank, n))
		return (free(rank), 0);
	free(rank);
	run_strategy(&p, o, &d);
	optimize(&p);
	print_ops(&p);
	if (o->bench)
		print_bench(&p, &d);
	ps_free(&p);
	return (1);
}

int	main(int argc, char **argv)
{
	t_opts	o;
	int		*vals;
	int		n;
	int		ok;

	o.strat = ST_ADAPTIVE;
	o.bench = 0;
	n = parse_args(argc, argv, &o, &vals);
	if (n < 0)
		return (ft_putendl_fd("Error", 2), 1);
	ok = 1;
	if (n > 0)
		ok = solve(vals, n, &o);
	free(vals);
	if (!ok)
		return (ft_putendl_fd("Error", 2), 1);
	return (0);
}
