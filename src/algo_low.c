/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_low.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by jucortes          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rot_cost(int size, int idx)
{
	if (idx <= size - idx)
		return (idx);
	return (size - idx);
}

static int	cheapest(t_ps *p)
{
	int	i;
	int	best;
	int	cost;
	int	min_cost;

	best = 0;
	min_cost = -1;
	i = -1;
	while (++i < p->b.size)
	{
		cost = rot_cost(p->b.size, i);
		cost += rot_cost(p->a.size, target_idx(&p->a, st_at(&p->b, i)));
		if (min_cost < 0 || cost < min_cost)
		{
			min_cost = cost;
			best = i;
		}
	}
	return (best);
}

static void	lis_sort(t_ps *p, int *keep, int rest)
{
	while (rest > 0)
	{
		if (keep[st_at(&p->a, 0)])
			ps_do(p, RA);
		else
		{
			ps_do(p, PB);
			rest--;
		}
	}
	while (p->b.size > 0)
	{
		bring(p, &p->b, cheapest(p));
		bring(p, &p->a, target_idx(&p->a, st_at(&p->b, 0)));
		ps_do(p, PA);
	}
	bring(p, &p->a, st_min_idx(&p->a));
}

void	sort_low(t_ps *p)
{
	int	*mem;
	int	n;

	p->name = "Low";
	p->cplx = "O(n)";
	n = p->a.size;
	mem = malloc(sizeof(int) * 3 * n);
	if (!mem)
	{
		sort_simple(p);
		return ;
	}
	ft_bzero(mem + 2 * n, sizeof(int) * n);
	lis_fill(&p->a, mem, mem + n);
	lis_sort(p, mem + 2 * n, n - lis_mark(&p->a, mem, mem + n, mem + 2 * n));
	free(mem);
}
