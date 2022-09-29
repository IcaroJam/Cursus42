# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:54:04 by ntamayo-          #+#    #+#              #
#    Updated: 2022/09/29 17:41:40 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################\/#######################################
#                                     Vars                                     #
#######################################/\#######################################

NAME	= phonebook#<<Your target-file here>>

CFLAGS	= -Wall -Werror -Wextra -std=c++98

VPATH	= ./ #<<your directories here (separated by :)>>

#----                                                                      ----#

SHRDSRC	= main.cpp Contact.cpp PhoneBook.cpp
#------------------------------------------------------------------------------#
SRCS	= $(SHRDSRC)

SHRDOBJ	= $(SHRDSRC:.cpp=.o)
#------------------------------------------------------------------------------#
OBJS	= $(SHRDOBJ)

#######################################\/#######################################
#                                     Ruls                                     #
#######################################/\#######################################

all:		$(NAME)

$(NAME):	compilemsg $(OBJS) $(LIBFT)
	@echo "\n \033[38;5;6m~Material stuff in a material world.\033[0m"
	@c++ $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n\033[38;5;6mReady to execute the protocol.\033[0m"

compilemsg:
	@echo "Pressing sourcefiles into sweet sweet objects..."

#----                                                                      ----#

%.o:	%.cpp
	@echo -n '>'
	@c++ $(CFLAGS) -c $<

#----                                                                      ----#

clean:
	@rm -f $(OBJS) $(BNSOBJS)
	@echo "\n\033[38;5;11mDeobjectifying...\033[0m\n"

fclean:		clean
	@rm -f $(NAME) $(BONUS)
	@echo "\033[38;5;1mNo more \033[4m$(NAME).\033[0m\n"

re:			fclean all

.PHONY: all compilemsg clean fclean re bonus
#-------------------------------------Tmpl-------------------------------------#

#TMPLSRC	= $(addprefix ./yourdirhere/, sourcefiles.c)

#TMPLOBJ	= $(addsuffix .o, $(notdir $(basename $(TMPLSRC))))
