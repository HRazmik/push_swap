NAME 	:= libftprintf.a

CC		:= cc

CFLAGS	:= -Wall -Wextra -Werror

AR		:= ar rcs

SRC 	:=	ft_printf.c \
			ft_printf_utils.c \
			ft_print_hex.c

OBJ		:= $(SRC:.c=.o)

all: $(NAME)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re