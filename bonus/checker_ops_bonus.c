/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by mancorte          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	swap_top(int *s, int n)
{
	int	tmp;

	if (n < 2)
		return ;
	tmp = s[0];
	s[0] = s[1];
	s[1] = tmp;
}

static void	push_top(int *dst, int *ndst, int *src, int *nsrc)
{
	int	x;

	if (*nsrc == 0)
		return ;
	x = src[0];
	ft_memmove(src, src + 1, sizeof(int) * (*nsrc - 1));
	(*nsrc)--;
	ft_memmove(dst + 1, dst, sizeof(int) * (*ndst));
	dst[0] = x;
	(*ndst)++;
}

static void	rot(int *s, int n, int reverse)
{
	int	x;

	if (n < 2)
		return ;
	if (reverse)
	{
		x = s[n - 1];
		ft_memmove(s + 1, s, sizeof(int) * (n - 1));
		s[0] = x;
	}
	else
	{
		x = s[0];
		ft_memmove(s, s + 1, sizeof(int) * (n - 1));
		s[n - 1] = x;
	}
}

void	ck_exec(t_ck *c, int code)
{
	if (code == 0 || code == 2)
		swap_top(c->a, c->na);
	if (code == 1 || code == 2)
		swap_top(c->b, c->nb);
	if (code == 3)
		push_top(c->a, &c->na, c->b, &c->nb);
	if (code == 4)
		push_top(c->b, &c->nb, c->a, &c->na);
	if (code == 5 || code == 7)
		rot(c->a, c->na, 0);
	if (code == 6 || code == 7)
		rot(c->b, c->nb, 0);
	if (code == 8 || code == 10)
		rot(c->a, c->na, 1);
	if (code == 9 || code == 10)
		rot(c->b, c->nb, 1);
}

int	ck_sorted(t_ck *c)
{
	int	i;

	if (c->nb != 0)
		return (0);
	i = 1;
	while (i < c->na)
	{
		if (c->a[i - 1] > c->a[i])
			return (0);
		i++;
	}
	return (1);
}
