/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by jucortes          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	run_checker(int *vals, int n)
{
	t_ck			c;
	unsigned char	*codes;
	int				count;
	int				i;

	if (!ck_read_ops(&codes, &count))
		return (0);
	c.a = vals;
	c.na = n;
	c.nb = 0;
	c.b = malloc(sizeof(int) * (n + 1));
	if (!c.b)
		return (free(codes), 0);
	i = 0;
	while (i < count)
		ck_exec(&c, codes[i++]);
	if (ck_sorted(&c))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free(c.b);
	free(codes);
	return (1);
}

int	main(int argc, char **argv)
{
	int	*vals;
	int	n;
	int	ok;

	if (argc < 2)
		return (0);
	n = ck_parse(argc, argv, &vals);
	if (n < 0)
		return (ft_putendl_fd("Error", 2), 1);
	ok = run_checker(vals, n);
	free(vals);
	if (!ok)
		return (ft_putendl_fd("Error", 2), 1);
	return (0);
}
