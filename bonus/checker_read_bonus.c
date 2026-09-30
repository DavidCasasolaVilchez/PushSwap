/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:00:00 by jucortes          #+#    #+#             */
/*   Updated: 2026/09/29 10:00:00 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ck_op_code(const char *line)
{
	const char	*names;
	int			i;

	names = "sa\0\0sb\0\0ss\0\0pa\0\0pb\0\0ra\0\0rb\0\0rr\0\0rra\0rrb\0rrr\0";
	i = 0;
	while (i < CK_NOPS)
	{
		if (!ft_strncmp(line, names + i * 4, 4))
			return (i);
		i++;
	}
	return (-1);
}

static char	*grow_buf(char *buf, size_t len, size_t *cap)
{
	char	*bigger;

	bigger = malloc(*cap * 2 + 1);
	if (bigger)
		ft_memcpy(bigger, buf, len);
	free(buf);
	*cap *= 2;
	return (bigger);
}

static char	*read_all(size_t *len)
{
	char	*buf;
	size_t	cap;
	ssize_t	r;

	cap = 4096;
	*len = 0;
	buf = malloc(cap + 1);
	while (buf)
	{
		if (*len == cap)
		{
			buf = grow_buf(buf, *len, &cap);
			continue ;
		}
		r = read(0, buf + *len, cap - *len);
		if (r <= 0)
			break ;
		*len += r;
	}
	return (buf);
}

static int	parse_lines(char *buf, size_t len, unsigned char *codes)
{
	size_t	i;
	size_t	start;
	int		count;
	int		code;

	i = 0;
	count = 0;
	buf[len] = '\0';
	while (i < len)
	{
		start = i;
		while (i < len && buf[i] != '\n')
			i++;
		buf[i] = '\0';
		code = ck_op_code(buf + start);
		if (code < 0)
			return (-1);
		codes[count++] = code;
		i++;
	}
	return (count);
}

int	ck_read_ops(unsigned char **codes, int *count)
{
	char	*buf;
	size_t	len;

	buf = read_all(&len);
	if (!buf)
		return (0);
	*codes = malloc(len + 1);
	if (!*codes)
		return (free(buf), 0);
	*count = parse_lines(buf, len, *codes);
	free(buf);
	if (*count < 0)
		return (free(*codes), 0);
	return (1);
}
