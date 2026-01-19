NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

MY_SOURCES = csp.c diu.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_tolower.c ft_toupper.c printf.c remaining.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)

clean:
	rm -f $(MY_OBJECTS)
	
fclean: clean
	rm -f $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $<

re: fclean all
