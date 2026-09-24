#include "../include/push_swap.h"

t_stack	*ft_init_stack()
{
	t_stack	*numbers;

	numbers = malloc(sizeof(t_stack));
	if (numbers == NULL)
		return (NULL);
	numbers->capacity = 42;
	numbers->size = 0;
	numbers->nums = malloc(sizeof(char) * numbers->capacity);
	if (numbers->nums == NULL)
		return (free(numbers), NULL);
	numbers->nums[0] = '\0';
	return (numbers);
}

t_context	*ft_init_context()
{
	t_context	*cx;

	cx = ft_malloc(sizeof(t_context));
	cx->alg = NULL;
	cx->bench = false;
	cx->can_space = true;
	cx->stack = ft_init_stack();
	return (cx);
}
