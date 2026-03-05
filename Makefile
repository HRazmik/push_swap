CC		:= cc

CFLAGS	:=  -g

NAME	:= push_swap

LIB_DIR     := libft
LIB_NAME    := ft
LIBFT       := $(LIB_DIR)/libft.a

SRC		:= main.c 

OBJ		:= $(SRC:.c=.o)

all: $(NAME)

%.c : %.o
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS)  $(OBJ) -L$(LIB_DIR) -l$(LIB_NAME) -o $(NAME)

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
