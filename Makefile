SRCS	=	$(shell find "." -name "*.c")

OBJS	= $(SRCS:.c=.o)

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I.

NAME 	= libftprintf.a

.c.o :
			$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME):
			$(CC) -c $(SRCS)
			ar rc libftprintf.a $(OBJS)
			ranlib libftprintf.a

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			$(RM) libftprintf.a

fclean:		clean
			$(RM) $(NAME)

.PHONY:		all clean fclean re .c.o

re:			clean fclean $(NAME)
