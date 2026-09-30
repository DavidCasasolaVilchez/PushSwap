/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by jucortes          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	st_init(t_stack *s, int cap)
{
	s->head = 0;
	s->size = 0;
	s->cap = cap;
	s->v = malloc(sizeof(int) * cap);
	return (s->v != NULL);
}

void	st_free(t_stack *s)
{
	free(s->v);
	s->v = NULL;
}

int	st_at(t_stack *s, int i)
{
	return (s->v[(s->head + i) % s->cap]);
}

void	st_push(t_stack *s, int x)
{
	s->head = (s->head + s->cap - 1) % s->cap;
	s->v[s->head] = x;
	s->size++;
}

int	st_pop(t_stack *s)
{
	int	x;

	x = s->v[s->head];
	s->head = (s->head + 1) % s->cap;
	s->size--;
	return (x);
}
