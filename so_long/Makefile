# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 11:00:45 by ntamayo-          #+#    #+#              #
#    Updated: 2022/06/17 18:56:41 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= main.c render_utils.c errors.c ./mapstuff/mapcheck.c .mapcstuff/mapcheckII.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Werror -Wextra -Imlx -c

MLX		= ./mlx/libmlx.a

LIBFT	= ./libft/libft.a



all:		$(NAME)

$(NAME):	$(OBJS) $(MLX) $(LIBFT)
	@gcc $(OBJS) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "Ejecutable finiquitado! A jugar :)"

$(MLX):
	@make -C ./mlx
	@echo "Libreriosa tortuosa"

$(LIBFT):
	@make -C ./libft
	@echo "Libft-ación"

.c.o:		$(SRCS)
	@gcc $(CFLAGS) -c $(SRCS)
	@echo "Objetos objetacionados"

clean:
	@rm -rf $(OBJS)
	@echo "Limpiando la habitación..."

libclean:
	@make -C ./mlx clean
	@make -C ./libft fclean

fclean:		clean
	@rm -rf $(NAME)

re:			fclean all

.PHONY: clean fclean re all libclean
