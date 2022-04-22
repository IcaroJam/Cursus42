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

# This action isn't really needed since make has it built-in when calling $(OBJS), but I like the msg :)
###################################
.c.o:	$(SRC)
	@gcc $(CFLAGS) -c $(SRC)
	@echo "Objetos creacionados :)"
###################################

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

.PHONY:	all fclean clean re
