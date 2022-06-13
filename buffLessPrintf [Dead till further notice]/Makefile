# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 15:29:38 by ntamayo-          #+#    #+#              #
#    Updated: 2022/05/28 17:44:23 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libftprintf.a

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	ft_printf.c flagsAndConversions.c

OBJS		=	$(SRC:.c=.o)



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
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "Limpieza profunda..."

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
