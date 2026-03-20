CC		:= cc

CFLAGS	:= -Wall -Wextra -Werror -g

NAME	:= push_swap 

LIB_DIR	:= libft

LIBFT	:= $(LIB_DIR)/libft.a

PF_DIR	:= ft_printf

PRINTF	:= $(PF_DIR)/libftprintf.a

LIBS	:= -L$(LIB_DIR) -lft -L$(PF_DIR) -lftprintf

SRC		:=	main.c \
			parser.c \
			parser_utils.c \
			bench.c \
			steck_imp.c \
			rotate_operation.c \
			revers_operation.c \
			swap_operation.c \
			push_operation.c \
			ChunkSort.c \
			insertionSort.c \
			mergeSort.c

OBJ		:= $(SRC:.c=.o)

all: $(NAME)

%.c : %.o
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS)  $(OBJ) $(LIBS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR) all

$(PRINTF):
	$(MAKE) -C $(PF_DIR)  all

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(PF_DIR)  clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(PF_DIR)  fclean

rm: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re rm
