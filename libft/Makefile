# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 18:48:04 by ntamayo-          #+#    #+#              #
#    Updated: 2022/06/15 15:32:00 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libft.a

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS		=	$(SRC:.c=.o)

BONUS_SRC	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS	= $(BONUS_SRC:.c=.o)



all:	bonus

# This action isn't really needed since make has it built-in when calling $(OBJS), but I like the msg :)
###################################
.c.o:	$(SRC)
	@gcc $(CFLAGS) -c $(SRC)
	@echo "Objetos creacionados :)"
###################################

$(NAME):	$(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Librerida fiquinitada ^^"

bonus:		$(SRC) $(BONUS_SRC)
	@gcc $(CFLAGS) -c $(SRC) $(BONUS_SRC)
	@echo "Objetitos con una pizca de sal ;)"
	@make -C printf
	@echo "F's printeadas"
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS) printf/*.o
	@echo "Bonus-ación completada B)"

clean:
	@make -C printf clean
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "Limpieza profunda..."

fclean:	clean
	@rm -f printf/libftprintf.a
	@rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re bonus
