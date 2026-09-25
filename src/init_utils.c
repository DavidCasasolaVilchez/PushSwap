#include "../include/push_swap.h"

/*t_list	*ft_init_stack()
{
	t_list		*node;

	node = ft_malloc(sizeof(t_list));
	node->content = NULL;
	node->next = NULL;
	return (node);
}*/

t_context	*ft_init_context()
{
	t_context	*cx;

	cx = ft_malloc(sizeof(t_context));
	cx->alg = NULL;
	cx->bench = false;
	cx->can_space = true;
	cx->stack = NULL;
	return (cx);
}
