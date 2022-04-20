NAME 	=	libft.a

CFLAGS	=	-Wall -Werror -Wextra

SRC		=	alpha_digit_alnum.c ascii_print.c memset_bzero_memcpy_memmove.c strlcpy_strlcat.c strlen.c

OBJS	=	$(SRC: .c=.o)



all:	$(NAME)

$(NAME):	.c.o
	ar rcs $(NAME) $(OBJ)

.c.o:	$(SRC)
	gcc $(CFLAGS) -c $(SRC)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
