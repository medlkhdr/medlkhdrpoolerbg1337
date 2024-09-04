CC = cc 
FLAGS = -Wall -Wextra -Werror -I./includes
FILES = srcs/ft_putchar srcs/ft_strcmp srcs/ft_strlen srcs/ft_putstr srcs/ft_swap 
.PHONY: all clean fclean re

all: libft.a

libft.a: $(FILES:=.o)
	ar rcs libft.a $(FILES:=.o)

%.o: %.c
	cc $(FLAGS) -o $@ -c $<

clean:
	rm -rf m $(FILES:=.o)

fclean: clean
	rm -rf libft.a

re: fclean all
