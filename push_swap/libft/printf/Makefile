# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 15:29:38 by ntamayo-          #+#    #+#              #
#    Updated: 2022/06/15 15:37:44 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	ft_printf.c ft_printf_utils_I.c char_string_conv.c digit_conv.c unsigned_conv.c hex_conv.c pointer_conv.c ptf_itoa.c ptf_lenghts.c flags_and_conversions.c

OBJS		=	$(SRC:.c=.o)



all:	$(OBJS)

.c.o:	$(SRC)
	@gcc $(CFLAGS) -c $(SRC)

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

re:		clean all

.PHONY:	all clean re
