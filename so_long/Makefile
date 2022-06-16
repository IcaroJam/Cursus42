# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 11:00:45 by ntamayo-          #+#    #+#              #
#    Updated: 2022/06/16 11:57:15 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= prueba.c render_utils.c

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
	@rm -rf $(OBJS)
	@echo "Limpiando la habitación..."

libclean:
	@make -C ./mlx clean

fclean:		clean
	@rm -rf $(NAME)

re:			fclean all

.PHONY: clean fclean re all libclean
