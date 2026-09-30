/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by jucortes          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_dup(int *v, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (v[i] == v[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

size_t	count_cap(int argc, char **argv)
{
	size_t	cap;
	int		i;

	cap = 1;
	i = 1;
	while (i < argc)
	{
		cap += ft_strlen(argv[i]) / 2 + 1;
		i++;
	}
	return (cap);
}
