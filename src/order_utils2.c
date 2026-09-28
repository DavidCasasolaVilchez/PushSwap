#include "../include/push_swap.h"

void	rra(t_context *cx)
{
	t_list	*aux;
	t_list	*node;

	aux = ft_lstlast(cx->stack_a);
	node = cx->stack_a;
	while (node->next != aux)
	{
		node = node->next;
	}
	node->next = NULL;
	ft_lstadd_front(&cx->stack_a, aux);
}

void	rrb(t_context *cx)
{
	t_list	*aux;
	t_list	*node;

	aux = ft_lstlast(cx->stack_b);
	node = cx->stack_b;
	while (node->next != aux)
	{
		node = node->next;
	}
	node->next = NULL;
	ft_lstadd_front(&cx->stack_b, aux);
}

void	rrr(t_context *cx)
{
	rra(cx);
	rrb(cx);
}
