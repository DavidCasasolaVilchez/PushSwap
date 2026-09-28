#include "../include/push_swap.h"

void reader(t_context	*cx)
{
	t_list	*nodo;
	t_stack	*val;
	int i = 0;

	if (cx == NULL || cx->stack_a == NULL || cx->stack_b == NULL)
		return ;
	printf("----- STACK A -----\n");
	nodo = cx->stack_a;
	while (nodo->next != NULL)
	{
		val = (t_stack	*)nodo->content;
		printf("%d-> %d\n", i++, val->value);
		nodo = nodo->next;
	}
	val = (t_stack	*)nodo->content;
	printf("%d-> %d\n", i++, val->value);

	printf("----- STACK B -----\n");
	i = 0;
	nodo = cx->stack_b;
	while (nodo->next != NULL)
	{
		val = (t_stack	*)nodo->content;
		printf("%d-> %d\n", i++, val->value);
		nodo = nodo->next;
	}
	val = (t_stack	*)nodo->content;
	printf("%d-> %d\n", i++, val->value);
}

int	main(int argc, char **argv)
{
	t_context	*cx = ft_check_args(argc, argv);

	reader(cx);
	ra(cx);
	printf("\n\n\n\n\n");
	reader(cx);

	printf("%s\n", "Correcto");
	return (ft_free_context(cx), 0);
}