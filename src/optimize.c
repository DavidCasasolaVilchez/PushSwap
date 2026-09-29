/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by mancorte          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	track(int op, int *na, int *nb)
{
	if (op == RA || op == RR)
		(*na)++;
	if (op == RB || op == RR)
		(*nb)++;
	if (op == RRA || op == RRR)
		(*na)--;
	if (op == RRB || op == RRR)
		(*nb)--;
	return (op >= RA);
}

static void	put_n(t_ps *p, int *w, int op, int cnt)
{
	while (cnt-- > 0)
		p->ops[(*w)++] = op;
}

static void	merge_common(t_ps *p, int *w, int *na, int *nb)
{
	int	c;

	c = 0;
	if (*na > 0 && *nb > 0)
	{
		c = *na;
		if (*nb < c)
			c = *nb;
		put_n(p, w, RR, c);
		*na -= c;
		*nb -= c;
	}
	else if (*na < 0 && *nb < 0)
	{
		c = -*na;
		if (-*nb < c)
			c = -*nb;
		put_n(p, w, RRR, c);
		*na += c;
		*nb += c;
	}
}

static void	emit_run(t_ps *p, int *w, int na, int nb)
{
	merge_common(p, w, &na, &nb);
	if (na > 0)
		put_n(p, w, RA, na);
	else
		put_n(p, w, RRA, -na);
	if (nb > 0)
		put_n(p, w, RB, nb);
	else
		put_n(p, w, RRB, -nb);
}

void	optimize(t_ps *p)
{
	int	r;
	int	w;
	int	na;
	int	nb;

	r = 0;
	w = 0;
	while (r < p->nops)
	{
		na = 0;
		nb = 0;
		while (r < p->nops && track(p->ops[r], &na, &nb))
			r++;
		emit_run(p, &w, na, nb);
		if (r < p->nops)
			p->ops[w++] = p->ops[r++];
	}
	p->nops = w;
}
