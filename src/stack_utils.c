#include "../include/push_swap.h"

t_list		*ft_create_node(int value, int index)
{
	t_list		*node;
	t_stack		*content;

	node = ft_malloc(sizeof(t_list));
	content = ft_malloc(sizeof(t_stack));
	content->index = index;
	content->value = value;
	node->content = content;
	node->next = NULL;
	return (node);
}