NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

MY_SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_atoi.c \
ft_strlen.c ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcat.c ft_strnstr.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memcmp.c ft_memchr.c \
ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_split.c

MY_FAIL = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

BONUS_FAIL = $(MY_FAIL:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)

# ar -> a command-line tool used to create static libraries
# r -> replace object files in the archive
# c → create the archive if it doesn’t exist
# s → add an index (for faster linking / symbol table)
# A symbol table is like a lookup table for all the functions and global variables in the .o files.

clean:
	rm -f $(MY_OBJECTS) $(BONUS_FAIL)
	
fclean: clean
	rm -f $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# ^ it only makes .c into .o files, and nothing else (maybe)
	
re: fclean all

bonus: $(BONUS_FAIL) $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS) $(BONUS_FAIL)
