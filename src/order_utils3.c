#include "../include/push_swap.h"

void	ra(t_context *cx)
{
	t_list	*aux;
	t_list	*last;

	last = cx->stack_a;
	aux = cx->stack_a->next;
	ft_lstadd_back(&cx->stack_a, last);
	last->next = NULL;
	cx->stack_a = aux;
}

void	rb(t_context *cx)
{
	t_list	*aux;
	t_list	*last;

	last = cx->stack_b;
	aux = cx->stack_b->next;
	ft_lstadd_back(&cx->stack_b, last);
	last->next = NULL;
	cx->stack_b = aux;
}

void	rr(t_context *cx)
{
	ra(cx);
	rb(cx);
}
