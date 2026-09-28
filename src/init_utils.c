#include "../include/push_swap.h"

t_context	*ft_init_context()
{
	t_context	*cx;

	cx = ft_malloc(sizeof(t_context));
	cx->alg = NULL;
	cx->bench = false;
	cx->can_space = true;
	cx->stack_a = NULL;
	cx->stack_b = NULL;
	return (cx);
}
