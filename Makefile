NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
INCLUDES	= -I. -I$(LIBFT_DIR)

SRC_DIR		= src
OBJ_DIR		= obj
BONUS_DIR	= bonus

SRC			= main.c parse.c parse_utils.c stack.c stack_ops.c ops.c \
			  optimize.c output.c bench.c disorder.c algo_utils.c \
			  algo_simple.c algo_medium.c algo_complex.c chunk_utils.c algo_low.c lis.c \
			  algo_small.c algo_adaptive.c
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

BONUS_SRC	= checker_bonus.c checker_parse_bonus.c checker_ops_bonus.c \
			  checker_read_bonus.c
BONUS_OBJ	= $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c push_swap.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c $(BONUS_DIR)/checker_bonus.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -I$(BONUS_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
