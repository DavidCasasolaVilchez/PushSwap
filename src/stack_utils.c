#include "../include/push_swap.h"

t_list		*ft_create_node(int value)
{
	t_list		*node;
	t_stack		*content;

	node = ft_malloc(sizeof(t_list));
	content = ft_malloc(sizeof(t_stack));
	content->value = value;
	node->content = content;
	node->next = NULL;
	return (node);
}

/*t_list	*ft_pop_node(t_list *lst)
{

}*/