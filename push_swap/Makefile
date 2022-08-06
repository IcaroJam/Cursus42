# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 12:10:23 by ntamayo-          #+#    #+#              #
#    Updated: 2022/08/06 19:02:14 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

LIBFT	= ./libft/libft.a

CFLAGS	= -Wall -Werror -Wextra


INSTSRC	= $(addprefix ./instructions/, swap.c push.c rotate.c revrotate.c)
STCKSRC	= $(addprefix ./stacks/, a_ops.c b_ops.c median.c)
SOLVSRC	= $(addprefix ./solving/, threesolve.c fivesolve.c solver.c)
PSMVSRC	= $(addprefix ./maindir/, main.c)
GLOBSRC	= errxit.c issorted.c input.c
BNUSSRC	= $(addprefix ./checkerdir/, bonus_main.c)
#------------------------------------------------------------------------------#
GLOBALS	= $(INSTSRC) $(GLOBSRC)
SRCS	= $(STCKSRC) $(SOLVSRC) $(PSMVSRC)


INSTOBJ	= $(addsuffix .o, $(notdir $(basename $(INSTSRC))))
STCKOBJ	= $(addsuffix .o, $(notdir $(basename $(STCKSRC))))
SOLVOBJ	= $(addsuffix .o, $(notdir $(basename $(SOLVSRC))))
PSMVOBJ	= $(addsuffix .o, $(notdir $(basename $(PSMVSRC))))
GLOBOBJ	= $(GLOBSRC:.c=.o)
BNUSOBJ	= $(addsuffix .o, $(notdir $(basename $(BNUSSRC))))
#------------------------------------------------------------------------------#
GLOBALO	= $(INSTOBJ) $(GLOBOBJ)
OBJS	= $(STCKOBJ) $(SOLVOBJ) $(PSMVOBJ)


################################################################################


all: $(NAME)

$(GLOBALO): $(GLOBALS)
	@gcc $(CFLAGS) -c $(GLOBALS)
	@echo "Global objs."

$(OBJS): $(SRCS)
	@gcc $(CFLAGS) -c $(SRCS)
	@echo "Objects objected."

$(BNUSOBJ): $(BNUSSRC)
	@gcc $(CFLAGS) -c $(BNUSSRC)
	@echo "Checker objs."

$(NAME): $(OBJS) $(GLOBALO) $(LIBFT)
	@gcc $(CFLAGS) $(OBJS) $(GLOBALO) -Llibft -lft -o $(NAME)
	@echo "Executable executableble :)"

$(LIBFT):
	@make -C ./libft
	@echo "Bookcases restocked."

bonus: $(BNUSOBJ) $(GLOBALO) $(LIBFT)
	@gcc $(CFLAGS) $(BNUSOBJ) $(GLOBALO) -Llibft -lft -o checker
	@echo "Checked the cheeky chekering."

clean:
	@rm -f $(OBJS) $(BNUSOBJ) $(GLOBALO)
	@echo "Cleaning up..."

libclean:
	@make -C ./libft fclean
	@echo "Library reduced to ashes."

fclean: clean
	@rm -f $(NAME) checker
	@echo "REALLY cleaning up..."

re: fclean all

.PHONY: all clean libclean fclean re bonus
