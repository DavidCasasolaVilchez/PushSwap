#include "push_swap.h"

void	*ft_malloc(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		exit(ERROR_EXIT);
	return (ptr);
}