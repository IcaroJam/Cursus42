# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:54:04 by ntamayo-          #+#    #+#              #
#    Updated: 2023/01/19 10:18:51 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################\/#######################################
#                                     Vars                                     #
#######################################/\#######################################

NAME	= abomination

CFLAGS	= -Wall -Werror -Wextra -std=c++98 -pedantic-errors

VPATH	= ./ #<<your directories here (separated by :)>>

# Echo needs the (non existent in macosx) -e flag to print colours in Linux
ECHO = echo -e
ifeq ($(shell uname -s),Darwin)
	ECHO = echo
endif

#----                                                                      ----#

SHRDSRC	= main.cpp
#------------------------------------------------------------------------------#
SRCS	= $(SHRDSRC)

SHRDOBJ	= $(SHRDSRC:.cpp=.o)
#------------------------------------------------------------------------------#
OBJS	= $(SHRDOBJ)

#######################################\/#######################################
#                                     Ruls                                     #
#######################################/\#######################################

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(ECHO) "\n \033[38;5;6m~Material stuff in a material world.\033[0m"
	@c++ $(CFLAGS) $(OBJS) -o $(NAME)
	@$(ECHO) "\n\033[38;5;6mReady to execute the protocol.\033[0m"
#----                                                                      ----#

%.o:	%.cpp
	@$(ECHO) -n '>'
	@c++ $(CFLAGS) -c $<

#----                                                                      ----#

clean:
	@rm -f $(OBJS) $(BNSOBJS)
	@$(ECHO) "\n\033[38;5;11mPressing objects into sweet sweet nothingness...\033[0m\n"

fclean:		clean
	@rm -f $(NAME) $(BONUS)
	@$(ECHO) "\033[38;5;1mNo more \033[4m$(NAME).\033[0m\n"

re:			fclean all

.PHONY: all clean fclean re

#-------------------------------------Tmpl-------------------------------------#

#TMPLSRC	= $(addprefix ./yourdirhere/, sourcefiles.c)

#TMPLOBJ	= $(addsuffix .o, $(notdir $(basename $(TMPLSRC))))
