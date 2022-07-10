# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 18:48:04 by ntamayo-          #+#    #+#              #
#    Updated: 2022/07/10 16:31:42 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	pipex

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	pipex.c errors.c processes.c commandparser.c pipesplit.c

OBJS		=	$(SRC:.c=.o)

BONUS_SRC	=	

BONUS_OBJS	=	$(BONUS_SRC:.c=.o)

LIBFT		=	./libft/libft.a



all:		$(NAME)

# This action isn't really needed since make has it built-in when calling $(OBJS), but I like the msg :)
###################################
.c.o:		$(SRC)
	@gcc $(CFLAGS) -c $(SRC)
	@echo "Objetos creacionados :)"
###################################

$(NAME):	$(OBJS) $(LIBFT)
	@gcc $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)
	@echo "Ready para pipear B)"

bonus:		all
#bonus:		$(BONUS_OBJS) $(LIBFT)
#	@gcc $(CFLAGS) $(BONUS_OBJS) -Llibft -lft -o $(NAME)
#	@echo "Múltiple pipeación B)"

$(LIBFT):
	@make -C ./libft
	@echo "Libftización..."

libclean:
	@make -C ./libft fclean
	@echo "Limpiando las estanterías libreras..."

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "Limpieza profunda..."

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean libclean re bonus .c.o
