/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by jucortes          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	int	i;

	i = 1;
	while (i < s->size)
	{
		if (st_at(s, i - 1) > st_at(s, i))
			return (0);
		i++;
	}
	return (1);
}

int	st_min_idx(t_stack *s)
{
	int	i;
	int	best;

	best = 0;
	i = 1;
	while (i < s->size)
	{
		if (st_at(s, i) < st_at(s, best))
			best = i;
		i++;
	}
	return (best);
}

int	st_max_idx(t_stack *s)
{
	int	i;
	int	best;

	best = 0;
	i = 1;
	while (i < s->size)
	{
		if (st_at(s, i) > st_at(s, best))
			best = i;
		i++;
	}
	return (best);
}

void	bring(t_ps *p, t_stack *s, int idx)
{
	int	back;
	int	fwd_op;
	int	back_op;

	fwd_op = RA;
	back_op = RRA;
	if (s == &p->b)
	{
		fwd_op = RB;
		back_op = RRB;
	}
	back = s->size - idx;
	if (idx <= back)
		while (idx-- > 0)
			ps_do(p, fwd_op);
	else
		while (back-- > 0)
			ps_do(p, back_op);
}

int	isqrt(int n)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}
