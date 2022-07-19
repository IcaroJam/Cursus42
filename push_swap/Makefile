# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 12:10:23 by ntamayo-          #+#    #+#              #
#    Updated: 2022/07/19 13:16:56 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

LIBFT	= libft.a

CFLAGS	= -Wall -Werror -Wextra


GLOBSRC	= errxit.c push_swap.c
#------------------------------------------------------------------------------#
SRCS	= $(GLOBSRC)



#------------------------------------------------------------------------------#
OBJS	= $(SRCS:.c=.o)


################################################################################


all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	@gcc $(CFLAGS) -c $(SRCS)
	@echo "Objects objected."
	@gcc $(CFLAGS) -Llibft -lft $(OBJS) -o $(NAME)
	@echo "Executable executableble :)"

bonus:

$(LIBFT):
	@make -C libft
	@echo "Bookcases restocked."

clean:
	@rm -f $(OBJS)
	echo "Cleaning up..."

libclean:
	@make -C libft fclean
	@echo "Library reduced to ashes."

fclean: clean
	@rm -f $(NAME)
	@echo "REALLY cleaning up..."

re: fclean all

.PHONY: all clean libclean fclean re bonus
