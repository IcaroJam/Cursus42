# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 15:29:38 by ntamayo-          #+#    #+#              #
#    Updated: 2022/06/09 10:46:59 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libftprintf.a

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	ft_printf.c ft_printf_utils_I.c char_string_conv.c digit_conv.c unsigned_conv.c ptf_itoa.c ptf_lenghts.c flags_and_conversions.c

OBJS		=	$(SRC:.c=.o)

BONUS_SRC	=	$(SRC)

BONUS_OBJS	=	$(BONUS_SRC:.c=.o)



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

bonus:		$(SRC) $(BONUS_SRC)
	@gcc $(CFLAGS) -c $(SRC) $(BONUS_SRC)
	@echo "Objetitos con una pizca de sal ;)"
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "Bonus-ación completada B)"

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "Limpieza profunda..."

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
