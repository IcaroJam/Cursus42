# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:54:04 by ntamayo-          #+#    #+#              #
#    Updated: 2023/06/01 16:34:35 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CMPFILE	= ./srcs/docker-compose.yml

all:
	docker-compose -f $(CMPFILE) up --build

clean:
	docker-compose -f $(CMPFILE) down

.PHONY: all clean
