NAME 	=	libft.a

CFLAGS	=	-Wall -Werror -Wextra

SRC		=	alpha_digit_alnum.c ascii_print.c memset_bzero_memcpy_memmove.c strlen.c

OBJS	=	$(SRC:.c=.o)



all:	$(NAME)

$(NAME):	.c.o
	@ar rcs $(NAME) $(OBJS)
	@echo "Librerida fiquinitada..."
	@make clean
	@echo "Y to limpito!"

.c.o:	$(SRC)
	@gcc $(CFLAGS) -c $(SRC)
	@echo "Objetos creacionados :)"

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

.PHONY:	all fclean clean re
