#include "../include/push_swap.h"

void	*ft_malloc(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		exit(ERROR_EXIT);
	return (ptr);
}

void	ft_free_context(t_context *cx)
{
	if (cx != NULL)
	{
		if (cx->stack != NULL)
			ft_free_stack(cx->stack);
		free(cx);
	}
}

void	ft_free_stack(t_stack *st)
{
	if (st != NULL)
	{
		if (st->nums != NULL)
			free(st->nums);
		free(st);
	}
}

void	ft_error_manager(t_context *cx)
{
	ft_free_context(cx);
	printf("Error\n");
	exit(ERROR_EXIT);
}

void	ft_realloc(t_context *cx, int nnum)
{
	int		*new;
	int		i;

	if (cx->stack->size + 2 > cx->stack->capacity)
	{
		cx->stack->capacity *= 2;
		if (cx->stack->capacity < cx->stack->size + 2)
			cx->stack->capacity = cx->stack->size + 2;
		new = malloc(cx->stack->capacity);
		if (new == NULL)
			ft_error_manager(cx);
		i = -1;
		while (++i < cx->stack->size)
			new[i] = cx->stack->nums[i];
		free(cx->stack->nums);
		cx->stack->nums = new;
	}
	cx->stack->nums[cx->stack->size] = nnum;
	cx->stack->size++;
}
