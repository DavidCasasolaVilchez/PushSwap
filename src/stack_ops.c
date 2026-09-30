/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by jucortes          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	st_swap(t_stack *s)
{
	int	tmp;
	int	i1;

	if (s->size < 2)
		return ;
	i1 = (s->head + 1) % s->cap;
	tmp = s->v[s->head];
	s->v[s->head] = s->v[i1];
	s->v[i1] = tmp;
}

void	st_rot(t_stack *s)
{
	int	x;

	if (s->size < 2)
		return ;
	x = st_pop(s);
	s->v[(s->head + s->size) % s->cap] = x;
	s->size++;
}

void	st_rrot(t_stack *s)
{
	int	x;

	if (s->size < 2)
		return ;
	x = st_at(s, s->size - 1);
	s->size--;
	st_push(s, x);
}
