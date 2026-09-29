/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by mancorte          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_int(const char *s, int *out)
{
	long	n;
	int		sign;

	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!*s)
		return (0);
	n = 0;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s++ - '0');
		if (n > 2147483648L)
			return (0);
	}
	n *= sign;
	*out = (int)n;
	return (*s == '\0' && n >= -2147483648L && n <= 2147483647L);
}

static int	parse_flag(const char *s, t_opts *o, int *given)
{
	int	strat;

	if (!ft_strncmp(s, "--bench", 8))
		return (o->bench = 1, 1);
	strat = -1;
	if (!ft_strncmp(s, "--simple", 9))
		strat = ST_SIMPLE;
	else if (!ft_strncmp(s, "--medium", 9))
		strat = ST_MEDIUM;
	else if (!ft_strncmp(s, "--complex", 10))
		strat = ST_COMPLEX;
	else if (!ft_strncmp(s, "--adaptive", 11))
		strat = ST_ADAPTIVE;
	if (strat < 0 || *given)
		return (0);
	*given = 1;
	o->strat = strat;
	return (1);
}

static int	add_tokens(char *arg, int *vals, int *n)
{
	char	**tok;
	int		i;
	int		ok;

	tok = ft_split(arg, ' ');
	if (!tok || !tok[0])
		return (free(tok), 0);
	ok = 1;
	i = 0;
	while (tok[i])
	{
		if (ok && !parse_int(tok[i], &vals[*n]))
			ok = 0;
		if (ok)
			(*n)++;
		free(tok[i++]);
	}
	free(tok);
	return (ok);
}

int	parse_args(int argc, char **argv, t_opts *o, int **vals)
{
	int	i;
	int	n;
	int	given;

	*vals = malloc(sizeof(int) * count_cap(argc, argv));
	if (!*vals)
		return (-1);
	i = 0;
	n = 0;
	given = 0;
	while (++i < argc)
	{
		if (!ft_strncmp(argv[i], "--", 2) && !parse_flag(argv[i], o, &given))
			return (free(*vals), -1);
		if (ft_strncmp(argv[i], "--", 2) && !add_tokens(argv[i], *vals, &n))
			return (free(*vals), -1);
	}
	if (has_dup(*vals, n))
		return (free(*vals), -1);
	return (n);
}
