/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by jucortes          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis_fill(t_stack *a, int *len, int *prv)
{
	int	i;
	int	j;

	i = -1;
	while (++i < a->size)
	{
		len[i] = 1;
		prv[i] = -1;
		j = -1;
		while (++j < i)
		{
			if (st_at(a, j) < st_at(a, i) && len[j] + 1 > len[i])
			{
				len[i] = len[j] + 1;
				prv[i] = j;
			}
		}
	}
}

int	lis_mark(t_stack *a, int *len, int *prv, int *keep)
{
	int	i;
	int	best;
	int	count;

	best = 0;
	i = 0;
	while (++i < a->size)
		if (len[i] > len[best])
			best = i;
	count = len[best];
	while (best >= 0)
	{
		keep[st_at(a, best)] = 1;
		best = prv[best];
	}
	return (count);
}

int	target_idx(t_stack *a, int x)
{
	int	i;
	int	best;

	best = -1;
	i = -1;
	while (++i < a->size)
		if (st_at(a, i) > x && (best < 0 || st_at(a, i) < st_at(a, best)))
			best = i;
	if (best < 0)
		best = st_min_idx(a);
	return (best);
}
