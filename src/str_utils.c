#include "../include/push_swap.h"

int		ft_str_check_match(const char *b, const char *t, int i)
{
	int	j;

	j = 0;
	while (t[j])
	{
		if (t[j] != b[i + j])
			return (false);
		j++;
	}
	if (t[j])
		return (false);
	return (true);
}

int		ft_str_search(const char *big, const char *little)
{
	int	i;

	i = -1;
	if (little[0] != '\0')
		while (big[++i])
			if (ft_str_check_match(big, little, i))
				return (true);
	return (false);
}

int		ft_str_is_num(char *s, int *index, t_context *cx)
{
	int		i;

	i = (int) *index;
	if (s[*index] == '-' || ft_isdigit(s[*index]))
		*index += 1;
	else
		return (false);
	while (s[*index] && ft_isdigit(s[*index]))
		*index += 1;
	if ((s[*index] == ' ' && cx->can_space && (ft_isdigit(s[*index + 1]) ||
		s[*index + 1] || s[*index + 1] == '-')) || !(s[*index]))
	{
		ft_lstadd_back(&cx->stack, ft_create_node(ft_atoi(s + i),
			ft_lstsize(cx->stack)));
		return (true);
	}
	else
		return (false);
}
