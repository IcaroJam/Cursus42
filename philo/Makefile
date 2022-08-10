# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:54:04 by ntamayo-          #+#    #+#              #
#    Updated: 2022/08/10 17:25:42 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################\/#######################################
#                                     Vars                                     #
#######################################/\#######################################

NAME	= philosophers

BONUS	= #<<Your bonus exec here>>

CFLAGS	= -Wall -Werror -Wextra

#----                                                                      ----#

SHRDSRC	= basic_utils.c input.c main.c
#------------------------------------------------------------------------------#
SRCS	= $(SHRDSRC)
BNSSRCS	= $(SHRDSRC)

SHRDOBJ	= $(SHRDSRC:.c=.o)
#------------------------------------------------------------------------------#
OBJS	= $(SHRDOBJ)
BNSOBJS	= $(SHRDOBJ)

#######################################\/#######################################
#                                     Ruls                                     #
#######################################/\#######################################

all:		$(NAME)

#bonus:		$(BONUS)

$(NAME):	$(OBJS)
	@echo "Material stuff in a material world."
	@gcc $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Ready to execute the protocol."

#$(BONUS):	$(BNSOBJS)
#	@echo "Bonus objects for ya chief."
#	@gcc $(CFLAGS) $(BNSOBJS) -o $(BONUS)
#	@echo "Look at all that extra."

#----                                                                      ----#

%.o:	%.c
	@gcc $(CFLAGS) -c $<

#----                                                                      ----#

clean:
	@rm -f $(OBJS) $(BNSOBJS)
	@echo "Deobjectifying..."

fclean:		clean
	@rm -f $(NAME) $(BONUS)
	@echo "No more $(NAME)."

re:			fclean all

.PHONY: all clean fclean re bonus
#-------------------------------------Tmpl-------------------------------------#

#TMPLSRC	= $(addprefix ./yourdirhere/, sourcefiles.c)

#TMPLOBJ	= $(addsuffix .o, $(notdir $(basename $(TMPLSRC))))
