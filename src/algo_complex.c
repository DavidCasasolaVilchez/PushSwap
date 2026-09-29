/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by mancorte          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_top(t_ps *p, int size)
{
	while (st_at(&p->a, 0) > st_at(&p->a, 1)
		|| (size == 3 && st_at(&p->a, 1) > st_at(&p->a, 2)))
	{
		if (st_at(&p->a, 0) > st_at(&p->a, 1))
			ps_do(p, SA);
		else
		{
			ps_do(p, RA);
			ps_do(p, SA);
			ps_do(p, RRA);
		}
	}
}

static void	scatter(t_ps *p, int loc, int lo, int size)
{
	int	s1;
	int	r;
	int	piece;

	s1 = size / 3;
	while (size-- > 0)
	{
		r = chunk_peek(p, loc);
		piece = (r >= lo + s1) + (r >= lo + 2 * s1);
		chunk_take(p, loc, dest_of(loc, piece));
	}
}

static void	chunk_sort(t_ps *p, int loc, int lo, int size)
{
	int	s1;
	int	i;

	if (size <= 3)
	{
		i = size;
		while (i-- > 0)
			chunk_take(p, loc, L_TA);
		if (size > 1)
			sort_top(p, size);
		return ;
	}
	s1 = size / 3;
	scatter(p, loc, lo, size);
	chunk_sort(p, dest_of(loc, 2), lo + 2 * s1, size - 2 * s1);
	chunk_sort(p, dest_of(loc, 1), lo + s1, s1);
	chunk_sort(p, dest_of(loc, 0), lo, s1);
}

void	sort_complex(t_ps *p)
{
	p->name = "Complex";
	p->cplx = "O(n log n)";
	if (!is_sorted(&p->a))
		chunk_sort(p, L_TA, 0, p->a.size);
}
