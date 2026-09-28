#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
// TODO : Borrar
#include <stdio.h>

#define ERROR_EXIT 1
#define SUCCESS_EXIT 0
#define false 0
#define true 1

typedef struct s_stack
{
	int		value;
}	t_stack;

typedef struct s_context
{
	int		can_space;
	int		bench;
	char	*alg;
	t_list	*stack_a;
	t_list	*stack_b;
}	t_context;


//? memory_utils
void		*ft_malloc(int size);
void		ft_error_manager(t_context *cx);
void		ft_free_context(t_context *cx);
void		ft_free_node(t_list *st);
void		ft_free_stacks(t_context *cx);

//? int_utils
t_context	*ft_init_context();

//? args_utils
t_context	*ft_check_args(int argc, char **argv);
int			ft_check_stack(char *s, t_context *cx);
int			ft_check_flag_strategy(char *s, t_context *cx);
int			ft_check_flag_bench(char *s, t_context *cx);
int			ft_str_check_num(char *s, t_context *cx);

//? str_utils
int			ft_str_search(const char *big, const char *little);
int			ft_str_check_match(const char *b, const char *t, int i);
int			ft_str_is_num(char *s, int *index, t_context *cx);

//? stack_utils
t_list		*ft_create_node(int value);

//? order_utils
void	sa(t_context *cx);
void	sb(t_context *cx);
void	ss(t_context *cx);
void	pa(t_context *cx);
void	pb(t_context *cx);
void	ra(t_context *cx);
void	rb(t_context *cx);
void	rr(t_context *cx);
void	rra(t_context *cx);
void	rrb(t_context *cx);
void	rrr(t_context *cx);

#endif