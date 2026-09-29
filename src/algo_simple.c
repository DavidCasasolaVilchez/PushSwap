/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by mancorte          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_ps *p)
{
	p->name = "Simple";
	p->cplx = "O(n^2)";
	while (p->a.size > 0 && !is_sorted(&p->a))
	{
		bring(p, &p->a, st_min_idx(&p->a));
		ps_do(p, PB);
	}
	while (p->b.size > 0)
		ps_do(p, PA);
}
