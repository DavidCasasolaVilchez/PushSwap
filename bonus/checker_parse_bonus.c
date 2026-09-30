/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parse_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by jucortes          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ck_parse_int(const char *s, int *out)
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
		if (ok && !ck_parse_int(tok[i], &vals[*n]))
			ok = 0;
		if (ok)
			(*n)++;
		free(tok[i++]);
	}
	free(tok);
	return (ok);
}

static int	has_dup(int *v, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
			if (v[i] == v[j])
				return (1);
	}
	return (0);
}

static size_t	count_cap(int argc, char **argv)
{
	size_t	cap;
	int		i;

	cap = 1;
	i = 1;
	while (i < argc)
		cap += ft_strlen(argv[i++]) / 2 + 1;
	return (cap);
}

int	ck_parse(int argc, char **argv, int **vals)
{
	int	i;
	int	n;

	*vals = malloc(sizeof(int) * count_cap(argc, argv));
	if (!*vals)
		return (-1);
	i = 1;
	n = 0;
	while (i < argc)
	{
		if (!add_tokens(argv[i++], *vals, &n))
			return (free(*vals), -1);
	}
	if (has_dup(*vals, n))
		return (free(*vals), -1);
	return (n);
}
