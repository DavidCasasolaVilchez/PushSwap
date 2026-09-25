#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_context	*cx = ft_check_args(argc, argv);

	t_list	*nodo;
	t_stack	*val;

	if (cx == NULL || cx->stack == NULL)
		return (ft_free_context(cx), 1);
	nodo = cx->stack;
	while (nodo->next != NULL)
	{
		val = (t_stack	*)nodo->content;
		printf("%d -> %d\n", val->index, val->value);
		nodo = nodo->next;
	}
	val = nodo->content;
	printf("%d -> %d\n", val->index, val->value);

	printf("%s\n", "Correcto");
	return (ft_free_context(cx), 0);
}