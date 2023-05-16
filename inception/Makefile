# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:54:04 by ntamayo-          #+#    #+#              #
#    Updated: 2023/05/16 15:20:36 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################\/#######################################
#                                     Vars                                     #
#######################################/\#######################################

NAME	= #<<Your target-file here>>

BONUS	= #<<Your bonus exec here>>

CFLAGS	= -Wall -Werror -Wextra

VPATH	= ./ #<<your directories here (separated by :)>>

# Echo needs the (non existent in macosx) -e flag to print colours in Linux
ECHO = echo -e
ifeq ($(shell uname -s),Darwin)
	ECHO = echo
endif

#----                                                                      ----#

SHRDSRC	= $(addprefix ./srcs/, )
#------------------------------------------------------------------------------#
SRCS	= $(SHRDSRC)
BNSSRCS	= $(SHRDSRC)

#------------------------------------------------------------------------------#
OBJS	= $(addprefix obj/, $(notdir $(SRCS:.c=.o)))
BNSOBJS	= $(addprefix obj/, $(notdir $(BNSSRCS:.c=.o)))

#######################################\/#######################################
#                                     Ruls                                     #
#######################################/\#######################################

all:		$(NAME)

#bonus:		$(BONUS)

$(NAME):	obj $(LIBFT) $(OBJS)
	@$(ECHO) "\n \033[38;5;6m~Material stuff in a material world.\033[0m"
	@gcc $(CFLAGS) $(OBJS) $(FTFLGS) -o $(NAME)
	@$(ECHO) "\n\033[38;5;6mReady to execute the protocol.\033[0m"

#$(BONUS):	obj $(BNSOBJS) $(LIBFT)
#	@$(ECHO) "\n \033[38;5;6m~Bonus objects for ya chief.\033[0m"
#	@gcc $(CFLAGS) $(BNSOBJS) $(FTFLGS) -o $(BONUS)
#	@$(ECHO) "\n\033[38;5;6mLook at all that extra.\033[0m"

obj:
	@mkdir obj

#----                                                                      ----#

obj/%.o:	%.c
	@$(ECHO) -n '>'
	@gcc $(CFLAGS) -c $< -o $@

#----                                                                      ----#

clean:
	@$(ECHO) "\n\033[38;5;11mPressing objects into sweet sweet nothingness...\033[0m\n"
	@rm -f obj

fclean:		clean
	@rm -f $(NAME) $(BONUS)
	@$(ECHO) "\033[38;5;1mNo more \033[4m$(NAME).\033[0m\n"

re:			fclean all

.PHONY: all clean fclean re bonus

#-------------------------------------Tmpl-------------------------------------#

#TMPLSRC	= $(addprefix ./yourdirhere/, sourcefiles.c)

#TMPLOBJ	= $(addsuffix .o, $(notdir $(basename $(TMPLSRC))))
