CC = gcc
#CFLAGS = -Wall -Wextra -Werror

SRCS = main.c
INCLUDED = includes
NAME = nameLove.a

OBJECT = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJECT)
	ar -rc $@ $(OBJECT)

clean:
	rm -f $(OBJECT)
fclean: clean
	rm -f $(NAME)
re : fclean all