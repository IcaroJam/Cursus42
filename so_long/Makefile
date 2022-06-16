# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 11:00:45 by ntamayo-          #+#    #+#              #
#    Updated: 2022/06/16 11:18:16 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= prueba.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Werror -Wextra -Imlx -c

MLX		= mlx/libmlx.a



all:		$(NAME)

$(NAME):	$(OBJS) $(MLX)
	@gcc $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "Ejecutable finiquitado! A jugar :)"

$(MLX):
	@make -C ./mlx
	@echo "Libreriosa tortuosa"

.c.o:		$(SRCS)
	@gcc $(CFLAGS) -c $(SRCS)
	@echo "Objetos objetacionados"

clean:
	@make -C ./mlx clean
	@rm -rf $(OBJS)
	@echo "Limpiando la habitación..."

fclean:		clean
	@rm -rf $(NAME)

re:			fclean all

.PHONY: clean fclean re all
