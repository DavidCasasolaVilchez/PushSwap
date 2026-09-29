/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by mancorte          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dis	disorder(int *v, int n)
{
	t_dis	d;
	int		i;
	int		j;

	d.mistakes = 0;
	d.total = 0;
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			d.total++;
			if (v[i] > v[j])
				d.mistakes++;
			j++;
		}
		i++;
	}
	return (d);
}

int	*to_ranks(int *v, int n)
{
	int	*rank;
	int	i;
	int	j;

	rank = malloc(sizeof(int) * (n + 1));
	if (!rank)
		return (NULL);
	i = 0;
	while (i < n)
	{
		rank[i] = 0;
		j = 0;
		while (j < n)
		{
			if (v[j] < v[i])
				rank[i]++;
			j++;
		}
		i++;
	}
	return (rank);
}
