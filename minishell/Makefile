# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:54:04 by ntamayo-          #+#    #+#              #
#    Updated: 2022/09/19 11:46:57 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################\/#######################################
#                                     Vars                                     #
#######################################/\#######################################

NAME	= minishell

LIBFT	= ./libft/libft.a

CFLAGS	= -Wall -Werror -Wextra

FTFLGS	= -Llibft -lft -lreadline

VPATH	= ./:./parser/:./builtins/ #<<your directories here (separated by :)>>

#----                                                                      ----#

SHRDSRC	= main.c
PARSSRC	= $(addprefix ./parser/, parsingutils.c parsermain.c lexingutils.c lexer.c expansion_utils.c copy_utils.c)
BLTNSRC	= $(addprefix ./builtins/, )
#------------------------------------------------------------------------------#
SRCS	= $(SHRDSRC) $(PARSSRC) $(BLTNSRC)

SHRDOBJ	= $(SHRDSRC:.c=.o)
PARSOBJ	= $(addsuffix .o, $(notdir $(basename $(PARSSRC))))
BLTNOBJ	= $(addsuffix .o, $(notdir $(basename $(BLTNSRC))))
#------------------------------------------------------------------------------#
OBJS	= $(SHRDOBJ) $(PARSOBJ) $(BLTNOBJ)

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
