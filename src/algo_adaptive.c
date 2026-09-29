/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by mancorte          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	regime(t_dis *d)
{
	if (d->mistakes * 5 < d->total)
		return (0);
	if (d->mistakes * 2 < d->total)
		return (1);
	return (2);
}

void	sort_adaptive(t_ps *p, t_dis *d)
{
	int	r;

	r = regime(d);
	if (p->a.size <= 5)
		sort_small(p);
	else if (r == 0)
		sort_low(p);
	else if (r == 1)
		sort_medium(p);
	else
		sort_complex(p);
	p->name = "Adaptive";
	if (r == 0)
		p->cplx = "O(n)";
	else if (r == 1)
		p->cplx = "O(n*sqrt(n))";
	else
		p->cplx = "O(n log n)";
}
