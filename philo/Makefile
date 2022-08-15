# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:54:04 by ntamayo-          #+#    #+#              #
#    Updated: 2022/08/15 11:34:19 by senari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################\/#######################################
#                                     Vars                                     #
#######################################/\#######################################

NAME	= philo

BONUS	= philo_bonus

CFLAGS	= -Wall -Werror -Wextra -pthread

VPATH	= ./:./mandatorydir:./bonusdir

#----                                                                      ----#

SHRDSRC	= basic_utils.c input.c clockstuff.c
THRDSRC	= $(addprefix ./mandatorydir/, main.c master_functions.c)
PRCSSRC	= $(addprefix ./bonusdir/, bonus_main.c)
#------------------------------------------------------------------------------#
SRCS	= $(SHRDSRC) $(THRDSRC)
BNSSRCS	= $(SHRDSRC) $(PRCSSRC)

SHRDOBJ	= $(SHRDSRC:.c=.o)
THRDOBJ	= $(addsuffix .o, $(notdir $(basename $(THRDSRC))))
PRCSOBJ	= $(addsuffix .o, $(notdir $(basename $(PRCSSRC))))
#------------------------------------------------------------------------------#
OBJS	= $(SHRDOBJ) $(THRDOBJ)
BNSOBJS	= $(SHRDOBJ) $(PRCSOBJ)

#######################################\/#######################################
#                                     Ruls                                     #
#######################################/\#######################################

all:		$(NAME)

bonus:		$(BONUS)

$(NAME):	$(OBJS)
	@echo "Material stuff in a material world."
	@gcc $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Ready to execute the protocol."

$(BONUS):	$(BNSOBJS)
	@echo "Bonus objects for ya chief."
	@gcc $(CFLAGS) $(BNSOBJS) -o $(BONUS)
	@echo "Look at all that extra."

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
