/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by mancorte          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_ps *p)
{
	int	x;
	int	y;
	int	z;

	x = st_at(&p->a, 0);
	y = st_at(&p->a, 1);
	z = st_at(&p->a, 2);
	if (x < y && y < z)
		return ;
	if (x > y && y < z && x < z)
		ps_do(p, SA);
	else if (x > y && y > z)
	{
		ps_do(p, SA);
		ps_do(p, RRA);
	}
	else if (x > y)
		ps_do(p, RA);
	else if (x < z)
	{
		ps_do(p, SA);
		ps_do(p, RA);
	}
	else
		ps_do(p, RRA);
}

void	sort_small(t_ps *p)
{
	p->name = "Small";
	p->cplx = "O(1)";
	if (p->a.size == 2 && !is_sorted(&p->a))
		ps_do(p, SA);
	while (p->a.size > 3 && !is_sorted(&p->a))
	{
		bring(p, &p->a, st_min_idx(&p->a));
		ps_do(p, PB);
	}
	if (p->a.size == 3)
		sort_three(p);
	while (p->b.size > 0)
		ps_do(p, PA);
}
