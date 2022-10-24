# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:54:04 by ntamayo-          #+#    #+#              #
#    Updated: 2022/10/24 11:26:33 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################\/#######################################
#                                     Vars                                     #
#######################################/\#######################################

NAME	= ZombiesHordeNight

CFLAGS	= -Wall -Werror -Wextra -std=c++98 -pedantic-errors

VPATH	= ./ #<<your directories here (separated by :)>>

#----                                                                      ----#

SHRDSRC	= main.cpp Zombie.cpp zombieHorde.cpp
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
	@echo -e "\n \033[38;5;6m~Material stuff in a material world.\033[0m"
	@c++ $(CFLAGS) $(OBJS) -o $(NAME)
	@echo -e "\n\033[38;5;6mReady to execute the protocol.\033[0m"

#----                                                                      ----#

%.o:	%.cpp
	@echo -n '>'
	@c++ $(CFLAGS) -c $<

#----                                                                      ----#

clean:
	@rm -f $(OBJS) $(BNSOBJS)
	@echo -e "\n\033[38;5;11mPressing objects into sweet sweet nothingness...\033[0m\n"

fclean:		clean
	@rm -f $(NAME) $(BONUS)
	@echo -e "\033[38;5;1mNo more \033[4m$(NAME).\033[0m\n"

re:			fclean all

.PHONY: all clean fclean re
#-------------------------------------Tmpl-------------------------------------#

#TMPLSRC	= $(addprefix ./yourdirhere/, sourcefiles.c)

#TMPLOBJ	= $(addsuffix .o, $(notdir $(basename $(TMPLSRC))))
