/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by mancorte          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks(t_ps *p, int size)
{
	int	pushed;
	int	r;

	pushed = 0;
	while (p->a.size > 0)
	{
		r = st_at(&p->a, 0);
		if (r < pushed + size)
		{
			ps_do(p, PB);
			if (r < pushed)
				ps_do(p, RB);
			pushed++;
		}
		else
			ps_do(p, RA);
	}
}

void	sort_medium(t_ps *p)
{
	int	size;

	p->name = "Medium";
	p->cplx = "O(n*sqrt(n))";
	size = 3 * isqrt(p->a.size) / 2;
	if (size < 1)
		size = 1;
	if (!is_sorted(&p->a))
		push_chunks(p, size);
	while (p->b.size > 0)
	{
		bring(p, &p->b, st_max_idx(&p->b));
		ps_do(p, PA);
	}
}
