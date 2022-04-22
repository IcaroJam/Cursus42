NAME 	=	libft.a

CFLAGS	=	-Wall -Werror -Wextra

SRC		=	alpha_digit_alnum.c ascii_print.c memset_bzero_memcpy_memmove.c strlen.c strlcpy_strlcat.c

OBJS	=	$(SRC:.c=.o)



all:	$(NAME)

# This action isn't really needed since make has it built-in when calling $(OBJS), but I like the msg :)
###################################
.c.o:	$(SRC)
	@gcc $(CFLAGS) -c $(SRC)
	@echo "Objetos creacionados :)"
###################################

$(NAME):	$(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Librerida fiquinitada ^^"

clean:
	@rm -f $(OBJS)
	@echo "Limpieza profunda..."

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
