# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:54:04 by ntamayo-          #+#    #+#              #
#    Updated: 2022/09/13 16:26:48 by phijano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################\/#######################################
#                                     Vars                                     #
#######################################/\#######################################

NAME	= minishell

LIBFT	= ./libft/libft.a

CFLAGS	= -Wall -Werror -Wextra -I /Users/$(USER)/.brew/opt/readline/include

FTFLGS	= -Llibft -lft -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include

VPATH	= ./:./executor/:./signals:./builtins #<<your directories here (separated by :)>>

#----                                                                      ----#

SHRDSRC	= main.c executor.c path.c exit_status.c signals.c builtins.c
#------------------------------------------------------------------------------#
SRCS	= $(SHRDSRC)

SHRDOBJ	= $(SHRDSRC:.c=.o)
#------------------------------------------------------------------------------#
OBJS	= $(SHRDOBJ)

#######################################\/#######################################
#                                     Ruls                                     #
#######################################/\#######################################

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	@echo "Material stuff in a material world."
	@gcc $(CFLAGS) $(OBJS) $(FTFLGS) -o $(NAME)
	@echo "Ready to execute the protocol."

$(LIBFT):
	@make -C ./libft
	@echo "Bookcases restocked."

#----                                                                      ----#

%.o:	%.c
	@gcc $(CFLAGS) -c $<

#----                                                                      ----#

clean:
	@rm -f $(OBJS)
	@echo "Deobjectifying..."

libclean:
	@make -C ./libft fclean
	@echo "Library reduced to ashes."

fclean:		clean
	@rm -f $(NAME)
	@echo "No more $(NAME)."

re:			fclean all

.PHONY: all clean libclean fclean re
#-------------------------------------Tmpl-------------------------------------#

#TMPLSRC	= $(addprefix ./yourdirhere/, sourcefiles.c)

#TMPLOBJ	= $(addsuffix .o, $(notdir $(basename $(TMPLSRC))))
