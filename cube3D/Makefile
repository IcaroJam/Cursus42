# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:54:04 by ntamayo-          #+#    #+#              #
#    Updated: 2023/03/06 14:54:11 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################\/#######################################
#                                     Vars                                     #
#######################################/\#######################################

NAME	= cube3D

BONUS	= #<<Your bonus exec here>>

LIBFT	= ./libft/libft.a

MLX		= ./MLX42/build/libmlx42.a

CFLAGS	= -Wall -Werror -Wextra

FTFLGS	= -Llibft -lft

VPATH	= ./:./src/:./src/parser/ #<<your directories here (separated by :)>>

# Echo needs the (non existent in macosx) -e flag to print colours in Linux
ECHO = echo -e
ifeq ($(shell uname -s),Darwin)
	ECHO = echo
endif

#----                                                                      ----#

SHRDSRC	= main.c
PARSSRC	= atouc.c
#------------------------------------------------------------------------------#
SRCS	= $(SHRDSRC) $(PARSSRC)
BNSSRCS	= $(SHRDSRC)

#------------------------------------------------------------------------------#
OBJS	= $(SRCS:.c=.o)
BNSOBJS	= $(SHRDOBJ)

#######################################\/#######################################
#                                     Ruls                                     #
#######################################/\#######################################

all:		$(NAME)

#bonus:		$(BONUS)

$(NAME):	$(LIBFT) $(MLX) $(OBJS)
	@$(ECHO) "\n \033[38;5;6m~Material stuff in a material world.\033[0m"
	@gcc $(CFLAGS) $(OBJS) $(FTFLGS) -o $(NAME)
	@$(ECHO) "\n\033[38;5;6mReady to execute the protocol.\033[0m"

#$(BONUS):	$(BNSOBJS) $(LIBFT)
#	@$(ECHO) "\n \033[38;5;6m~Bonus objects for ya chief.\033[0m"
#	@gcc $(CFLAGS) $(BNSOBJS) $(FTFLGS) -o $(BONUS)
#	@$(ECHO) "\n\033[38;5;6mLook at all that extra.\033[0m"

$(LIBFT):
	@make -C ./libft
	@$(ECHO) "\n \033[38;5;35m~Bookcases restocked.\033[0m"

$(MLX):
	@$(ECHO) "\n\033[38;5;202mMLX is being built. STAND STILL!!!\n\033[0m"
	@cmake -S MLX42 -B MLX42/build # build here refers to the outputfolder.
	@cmake --build MLX42/build -j4 # or do make -C build -j4
	@$(ECHO) "\n \033[38;5;35m~MLX built in all it's glory.\033[0m"

#----                                                                      ----#

%.o:	%.c
	@$(ECHO) -n '>'
	@gcc $(CFLAGS) -c $<

#----                                                                      ----#

clean:
	@rm -f $(OBJS) $(BNSOBJS)
	@$(ECHO) "\n\033[38;5;11mPressing objects into sweet sweet nothingness...\033[0m\n"

libclean:
	@make -C ./libft fclean
	@$(ECHO) "\n\033[38;5;202m/Library reduced to ashes\\ \n\033[0m"
	@make -C ./MLX42/build clean
	@$(ECHO) "\n\033[38;5;202m/MLX banished from this land\\ \n\033[0m"

fclean:		clean
	@rm -f $(NAME) $(BONUS)
	@$(ECHO) "\033[38;5;1mNo more \033[4m$(NAME).\033[0m\n"

re:			fclean all

.PHONY: all clean libclean fclean re bonus

#-------------------------------------Tmpl-------------------------------------#

#TMPLSRC	= $(addprefix ./yourdirhere/, sourcefiles.c)

#TMPLOBJ	= $(addsuffix .o, $(notdir $(basename $(TMPLSRC))))
