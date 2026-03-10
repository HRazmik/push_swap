CC		:= cc

CFLAGS	:= -Wall -Wextra -Werror -g

NAME	:= push_swap 

LIB_DIR	:= libft

LIBFT	:= $(LIB_DIR)/libft.a

SRC		:=	main.c \
			parser.c \
			parser_utils.c \
			disorder.c \
			steck_imp.c

OBJ		:= $(SRC:.c=.o)

all: $(NAME)

%.c : %.o
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS)  $(OBJ) -L$(LIB_DIR) -lft -o $(NAME)

$(LIBFT): 
	$(MAKE) -C $(LIB_DIR) all

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
