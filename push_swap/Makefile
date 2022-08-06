# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 12:10:23 by ntamayo-          #+#    #+#              #
#    Updated: 2022/08/06 12:21:12 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

LIBFT	= ./libft/libft.a

CFLAGS	= -Wall -Werror -Wextra


INSTSRC	= $(addprefix ./instructions/, swap.c push.c rotate.c revrotate.c)
STCKSRC	= $(addprefix ./stacks/, a_ops.c b_ops.c)
SOLVSRC	= $(addprefix ./solving/, threesolve.c fivesolve.c solver.c)
GLOBSRC	= errxit.c main.c median.c issorted.c
#------------------------------------------------------------------------------#
SRCS	= $(GLOBSRC) $(INSTSRC) $(STCKSRC) $(SOLVSRC)


INSTOBJ	= $(addsuffix .o, $(notdir $(basename $(INSTSRC))))
STCKOBJ	= $(addsuffix .o, $(notdir $(basename $(STCKSRC))))
SOLVOBJ	= $(addsuffix .o, $(notdir $(basename $(SOLVSRC))))
GLOBOBJ	= $(GLOBSRC:.c=.o)
#------------------------------------------------------------------------------#
OBJS	= $(GLOBOBJ) $(INSTOBJ) $(STCKOBJ) $(SOLVOBJ)


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
