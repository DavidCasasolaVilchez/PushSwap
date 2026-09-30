/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by jucortes          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dest_of(int loc, int piece)
{
	return ("321320310210"[loc * 3 + piece] - '0');
}

int	chunk_peek(t_ps *p, int loc)
{
	if (loc == L_TA)
		return (st_at(&p->a, 0));
	if (loc == L_BA)
		return (st_at(&p->a, p->a.size - 1));
	if (loc == L_TB)
		return (st_at(&p->b, 0));
	return (st_at(&p->b, p->b.size - 1));
}

static void	from_a(t_ps *p, int dest)
{
	if (dest == L_BA)
		ps_do(p, RA);
	else if (dest == L_TB)
		ps_do(p, PB);
	else if (dest == L_BB)
	{
		ps_do(p, PB);
		ps_do(p, RB);
	}
}

static void	from_b(t_ps *p, int dest)
{
	if (dest == L_BB)
		ps_do(p, RB);
	else if (dest == L_TA)
		ps_do(p, PA);
	else if (dest == L_BA)
	{
		ps_do(p, PA);
		ps_do(p, RA);
	}
}

void	chunk_take(t_ps *p, int loc, int dest)
{
	if (loc == L_BA)
		ps_do(p, RRA);
	if (loc == L_BB)
		ps_do(p, RRB);
	if (loc == L_TA || loc == L_BA)
		from_a(p, dest);
	else
		from_b(p, dest);
}
