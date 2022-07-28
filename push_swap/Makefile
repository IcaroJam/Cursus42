# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 12:10:23 by ntamayo-          #+#    #+#              #
#    Updated: 2022/07/28 12:30:59 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

LIBFT	= ./libft/libft.a

CFLAGS	= -Wall -Werror -Wextra


INSTSRC	= $(addprefix ./instructions/, swap.c push.c rotate.c revrotate.c)
GLOBSRC	= errxit.c main.c median.c threesolve.c issorted.c
#------------------------------------------------------------------------------#
SRCS	= $(GLOBSRC) $(INSTSRC)


INSTOBJ	= $(addsuffix .o, $(notdir $(basename $(INSTSRC))))
GLOBOBJ	= $(GLOBSRC:.c=.o)
#------------------------------------------------------------------------------#
OBJS	= $(GLOBOBJ) $(INSTOBJ)


################################################################################


all: $(NAME)

$(OBJS): $(SRCS)
	@gcc $(CFLAGS) -c $(SRCS)
	@echo "Objects objected."

$(NAME): $(OBJS) $(LIBFT)
	@gcc $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)
	@echo "Executable executableble :)"

$(LIBFT):
	@make -C ./libft
	@echo "Bookcases restocked."

clean:
	@rm -f $(OBJS)
	@echo "Cleaning up..."

libclean:
	@make -C ./libft fclean
	@echo "Library reduced to ashes."

fclean: clean
	@rm -f $(NAME)
	@echo "REALLY cleaning up..."

re: fclean all

.PHONY: all clean libclean fclean re
