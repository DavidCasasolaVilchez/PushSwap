#include "../include/push_swap.h"

void	*ft_malloc(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		exit(ERROR_EXIT);
	return (ptr);
}
void	ft_free_node(t_list *st)
{
	if (st != NULL)
	{
		if (st->content != NULL)
			free(st->content);
		free(st);
	}
}

void	ft_free_stacks(t_context *cx)
{
	t_list	*i;
	t_list	*n;

	i = cx->stack_a;
	while (i->next != NULL)
	{
		n = i->next;
		ft_free_node(i);
		i = n;
	}
	ft_free_node(i);
	i = cx->stack_b;
	while (i->next != NULL)
	{
		n = i->next;
		ft_free_node(i);
		i = n;
	}
	ft_free_node(i);
	
}

void	ft_free_context(t_context *cx)
{
	if (cx != NULL)
	{
		ft_free_stacks(cx);
		free(cx);
	}
}

void	ft_error_manager(t_context *cx)
{
	ft_free_context(cx);
	printf("Error\n");
	exit(ERROR_EXIT);
}
