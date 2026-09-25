#include "../include/push_swap.h"

t_context	*ft_check_args(int argc, char **argv)
{
	int			i;
	t_context	*cx;

	if (argc <= 1)
		exit(SUCCESS_EXIT);
	i = 1;
	cx = ft_init_context();
	while (i < argc)
	{
		if (ft_check_flag_strategy(argv[i], cx) ||
			ft_check_flag_bench(argv[i], cx) || ft_str_check_num(argv[i], cx))
			i++;
		else
			ft_error_manager(cx);
	}
	return (cx);
}

int		ft_check_flag_strategy(char *s, t_context *cx)
{
	int		index;
	int		exist;
	char	*flags[5];
	
	flags[0] = "--simple";
	flags[1] = "--medium";
	flags[2] = "--complex";
	flags[3] = "--adaptive";
	flags[4] = NULL;
	index = -1;
	exist = false;
	while ((cx->alg == NULL) && !exist && flags[++index])
		exist = ft_str_search(s, flags[index]);
	if (exist)
		cx->alg = flags[index];
	return (exist);
}

int		ft_check_flag_bench(char *s, t_context *cx)
{
	int		exist;

	exist = ft_str_search(s, "--bench");
	if (cx->bench)
		exist = false;
	else
		cx->bench = exist;
	return (exist);
}

int		ft_str_check_num(char *s, t_context *cx)
{
	int		i;

	i = 0;
	while (s[i])
		if (ft_str_is_num(s, &i, cx))
			if (!s[i])
			{
				cx->can_space = false;
				return (true);
			}
			else
				i++;
		else
			return (false);
	cx->can_space = false;
	return (true);
}
