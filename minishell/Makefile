# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:54:04 by ntamayo-          #+#    #+#              #
#    Updated: 2022/09/16 13:40:19 by phijano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################\/#######################################
#                                     Vars                                     #
#######################################/\#######################################

NAME	= minishell

LIBFT	= ./libft/libft.a

CFLAGS	= -Wall -Werror -Wextra -I /Users/$(USER)/.brew/opt/readline/include
#comprobar si hace falta el -I ... aqui, lo puse a lo bruto.
FTFLGS	= -Llibft -lft -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include

VPATH	= ./:./parser/:./executor/:./signals:./builtins #<<your directories here (separated by :)>>

#----                                                                      ----#

SHRDSRC	= main.c
PARSSRC	= $(addprefix ./parser/, parsingutils.c parsermain.c lexingutils.c lexer.c expansion_utils.c copy_utils.c)
EXECSRC	= $(addprefix ./executor/, executor.c path.c exit_status.c)
BUILSRC	= $(addprefix ./builtins/, builtins.c)
SIGNSRC	= $(addprefix ./signals/, signals.c)

#------------------------------------------------------------------------------#
SRCS	= $(SHRDSRC) $(PARSSRC) $(EXECSRC) $(BUILSRC) $(SIGNSRC)

SHRDOBJ	= $(SHRDSRC:.c=.o)
PARSOBJ	= $(addsuffix .o, $(notdir $(basename $(PARSSRC))))
EXECOBJ	= $(addsuffix .o, $(notdir $(basename $(EXECSRC))))
BUILOBJ	= $(addsuffix .o, $(notdir $(basename $(BUILSRC))))
SIGNOBJ	= $(addsuffix .o, $(notdir $(basename $(SIGNSRC))))

#------------------------------------------------------------------------------#
OBJS	= $(SHRDOBJ) $(PARSOBJ) $(EXECOBJ) $(BUILOBJ) $(SIGNOBJ)

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
