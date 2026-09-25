#include "../include/push_swap.h"

void	*ft_malloc(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		exit(ERROR_EXIT);
	return (ptr);
}
void	ft_free_stack(t_list *st)
{
	if (st != NULL)
	{
		if (st->content != NULL)
			free(st->content);
		free(st);
	}
}

void	ft_free_context(t_context *cx)
{
	t_list	*n;

	if (cx != NULL)
	{
		while (cx->stack != NULL)
		{
			n = cx->stack->next;
			ft_free_stack(cx->stack);
			cx->stack = n;
		}
		free(cx);
	}
}

void	ft_error_manager(t_context *cx)
{
	ft_free_context(cx);
	printf("Error\n");
	exit(ERROR_EXIT);
}
