NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -Iinclude
RM := rm -f

LIBFT := include/libft.a
SRC_DIR := src
OBJ_DIR := obj

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: all clean fclean re run test test-valid test-errors

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -g -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

run: $(NAME)
	valgrind --leak-check=full ./$(NAME) -12 12 1 123 -123 12 78 "--bench"

test: test-valid test-errors

test-valid: $(NAME)
	@printf '\n== Sin argumentos ==\n'
	@./$(NAME)
	@printf '\n== Numeros separados ==\n'
	@./$(NAME) 1 2 3 4 5
	@printf '\n== Numeros negativos y positivos ==\n'
	@./$(NAME) -12 0 12 -123 78

test-errors: $(NAME)
	@printf '\n== Argumento no numerico (se espera Error) ==\n'
	@./$(NAME) 1 hello 3 || true
	@printf '\n== Flag desconocido (se espera Error) ==\n'
	@./$(NAME) --unknown || true

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
