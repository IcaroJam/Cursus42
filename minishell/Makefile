# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:54:04 by ntamayo-          #+#    #+#              #
#    Updated: 2022/09/05 17:52:55 by phijano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################\/#######################################
#                                     Vars                                     #
#######################################/\#######################################

NAME	= minishell

LIBFT	= ./libft/libft.a

CFLAGS	= -Wall -Werror -Wextra

FTFLGS	= -Llibft -lft -lreadline

VPATH	= ./ #<<your directories here (separated by :)>>

#----                                                                      ----#

SHRDSRC	= main.c execute.c ft_path.c
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
