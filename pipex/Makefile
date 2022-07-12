# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 18:48:04 by ntamayo-          #+#    #+#              #
#    Updated: 2022/07/12 17:35:13 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	pipex

CFLAGS		=	-Wall -Werror -Wextra

GENPURP		=	errors.c commandparser.c pipesplit.c

GENPURP_OBJ	=	$(GENPURP:.c=.o)

SRC			=	./mandatory/pipex.c ./mandatory/processes.c

OBJS		=	$(addsuffix .o, $(notdir $(basename $(SRC))))

BONUS_SRC	=	./bonus/pipex_bonus.c ./bonus/processes_bonus.c

BONUS_OBJS	=	$(addsuffix .o, $(notdir $(basename $(BONUS_SRC))))

LIBFT		=	./libft/libft.a



all:			$(NAME)

$(OBJS):	$(SRC) $(GENPURP)
	@gcc $(CFLAGS) -c $(SRC) $(GENPURP)
	@echo "Objetos creacionados :)"

$(BONUS_OBJS):	$(BONUS_SRC) $(GENPURP)
	@gcc $(CFLAGS) -c $(BONUS_SRC) $(GENPURP)
	@echo "Objetos de bonus creacionados :)"

$(NAME):		$(OBJS) $(LIBFT)
	@gcc $(CFLAGS) $(OBJS) $(GENPURP_OBJ) -Llibft -lft -o $(NAME)
	@echo "Ready para pipear B)"

# bonus:	all
bonus:			$(BONUS_OBJS) $(LIBFT)
	@gcc $(CFLAGS) $(BONUS_OBJS) $(GENPURP_OBJ) -Llibft -lft -o $(NAME)
	@echo "Múltiple pipeación B)"

$(LIBFT):
	@make -C ./libft
	@echo "Libftización..."

libclean:
	@make -C ./libft fclean
	@echo "Limpiando las estanterías libreras..."

clean:
	@rm -f $(OBJS) $(BONUS_OBJS) $(GENPURP_OBJ)
	@echo "Limpieza profunda..."

fclean:			clean
	@rm -f $(NAME)

re:				fclean all

.PHONY:	all clean fclean libclean re bonus .c.o
