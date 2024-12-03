CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_putnbr.c ft_putstr.c ft_hexa.c ft_pointer.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all:$(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o:%.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean