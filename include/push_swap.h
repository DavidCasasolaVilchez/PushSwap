#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

#define ERROR_EXIT 1
#define SUCCESS_EXIT 0
#define false 0
#define true 1

typedef struct s_stack
{
	int		*nums;
	int		size;
	int		capacity;
}	t_stack;

typedef struct s_context
{
	int		can_space;
	int		bench;
	char	*alg;
	t_stack	*stack;
}	t_context;


//? memory_utils
void		*ft_malloc(int size);
void		ft_realloc(t_context *cx, int nnum);
void		ft_error_manager(t_context *cx);
void		ft_free_context(t_context *cx);
void		ft_free_stack(t_stack *st);

//? int_utils
t_context	*ft_init_context();
t_stack		*ft_init_stack();

//? args_utils
void		ft_check_args(int argc, char **argv);
int			ft_check_stack(char *s, t_context *cx);
int			ft_check_flag_strategy(char *s, t_context *cx);
int			ft_check_flag_bench(char *s, t_context *cx);
int			ft_str_check_num(char *s, t_context *cx);

//? str_utils
int			ft_str_search(const char *big, const char *little);
int			ft_str_check_match(const char *b, const char *t, int i);
int			ft_str_is_num(char *s, int *index, t_context *cx);


#endif