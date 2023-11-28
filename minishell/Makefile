# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:54:04 by ntamayo-          #+#    #+#              #
#    Updated: 2023/11/28 14:56:54 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################\/#######################################
#                                     Vars                                     #
#######################################/\#######################################

NAME	= minishell

LIBFT	= ./libft/libft.a

CFLAGS	= -Wall -Werror -Wextra -I /Users/$(USER)/.brew/opt/readline/include

FTFLGS	= -Llibft -lft -lreadline -L /Users/$(USER)/.brew/opt/readline/lib

VPATH	= ./:./parser/:./executor/:./signals:./builtins #<<your directories here (separated by :)>>

#----                                                                      ----#

SHRDSRC	= main.c utils.c
PARSSRC	= $(addprefix ./parser/, parsingutils.c parsermain.c lexingutils.c lexer.c expansion.c expansion_utils.c copy_utils.c)
EXECSRC	= $(addprefix ./executor/, executor.c fds.c doc_here.c check_cmds.c execute.c path.c exit_status.c)
BLTNSRC	= $(addprefix ./builtins/, builtins.c, exit.c cd.c echo.c pwd.c environ.c export.c unset.c)
SIGNSRC	= $(addprefix ./signals/, signals.c)

#------------------------------------------------------------------------------#

SRCS	= $(SHRDSRC) $(PARSSRC) $(EXECSRC) $(BLTNSRC) $(SIGNSRC)

SHRDOBJ	= $(SHRDSRC:.c=.o)
PARSOBJ	= $(addsuffix .o, $(notdir $(basename $(PARSSRC))))
EXECOBJ	= $(addsuffix .o, $(notdir $(basename $(EXECSRC))))
BLTNOBJ	= $(addsuffix .o, $(notdir $(basename $(BLTNSRC))))
SIGNOBJ	= $(addsuffix .o, $(notdir $(basename $(SIGNSRC))))

#------------------------------------------------------------------------------#

OBJS	= $(addprefix obj/, $(SHRDOBJ) $(PARSOBJ) $(EXECOBJ) $(BLTNOBJ) $(SIGNOBJ))

#######################################\/#######################################
#                                     Ruls                                     #
#######################################/\#######################################

all:		$(NAME)

$(NAME):	obj $(LIBFT) $(OBJS)
	@printf "\n \033[38;5;6m~Material stuff in a material world.\033[0m"
	@gcc $(CFLAGS) $(OBJS) $(FTFLGS) -o $(NAME)
	@printf "\n\033[38;5;35mReady to execute the protocol.\033[0m\n"

$(LIBFT):
	@make -C ./libft
	@printf "\n \033[38;5;35m~Bookcases restocked.\033[0m\n"

obj:
	@mkdir obj

#----                                                                      ----#

obj/%.o:	%.c
	@gcc $(CFLAGS) -c $< -o $@
	@printf "\r\033[38;5;6m[$<]\033[0m Compiled!\n"
	@$(foreach file,$(shell ls obj/),printf '>';)

#----                                                                      ----#

clean:
	@rm -rf obj
	@printf "\n\033[38;5;11mPressing objects into sweet sweet nothingness...\033[0m\n"

libclean:
	@make -C ./libft fclean
	@printf "\033[38;5;202m/Library reduced to ashes\\ \n\033[0m"

fclean:		clean
	@rm -f $(NAME)
	@printf "\033[38;5;1mNo more \033[4m$(NAME).\033[0m\n\n"

re:			fclean all

.PHONY: all clean libclean fclean re
#-------------------------------------Tmpl-------------------------------------#

#TMPLSRC	= $(addprefix ./yourdirhere/, sourcefiles.c)

#TMPLOBJ	= $(addsuffix .o, $(notdir $(basename $(TMPLSRC))))
