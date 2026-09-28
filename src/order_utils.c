#include "../include/push_swap.h"

void	sa(t_context *cx)
{
	t_list	*aux;
	t_stack	*aux_a;
	t_stack	*aux_b;

	if (cx == NULL || cx->stack_a == NULL || cx->stack_a->next == NULL)
		return ;
	aux = cx->stack_a->next;
	aux_a = (t_stack	*)aux->content;
	aux_b = (t_stack	*)cx->stack_a->content;
	cx->stack_a->content = aux_a;
	aux->content = aux_b;
}

void	sb(t_context *cx)
{
	t_list	*aux;
	t_stack	*aux_a;
	t_stack	*aux_b;

	if (cx == NULL || cx->stack_b == NULL || cx->stack_b->next == NULL)
		return ;
	aux = cx->stack_b->next;
	aux_a = (t_stack	*)aux->content;
	aux_b = (t_stack	*)cx->stack_b->content;
	cx->stack_b->content = aux_a;
	aux->content = aux_b;
}

void	ss(t_context *cx)
{
	sa(cx);
	sb(cx);
}


void	pa(t_context *cx)
{
	t_list	*aux;

	aux = cx->stack_b->next;
	ft_lstadd_front(&cx->stack_a, cx->stack_b);
	cx->stack_b = aux;
}
void	pb(t_context *cx)
{
	t_list	*aux;

	aux = cx->stack_a->next;
	ft_lstadd_front(&cx->stack_b, cx->stack_a);
	cx->stack_a = aux;
}
