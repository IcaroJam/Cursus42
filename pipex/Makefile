# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 18:48:04 by ntamayo-          #+#    #+#              #
#    Updated: 2022/07/12 15:58:42 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	pipex

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	./mandatory/pipex.c errors.c ./mandatory/processes.c commandparser.c pipesplit.c

OBJS		=	$(addsuffix .o, $(notdir $(basename $(SRC))))

BONUS_SRC	=	

BONUS_OBJS	=	$(BONUS_SRC:.c=.o)

LIBFT		=	./libft/libft.a



all:		$(NAME)

# This action isn't really needed since make has it built-in when calling $(OBJS), but I like the msg :)
###################################
$(OBJS):	$(SRC)
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
