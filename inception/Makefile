# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntamayo- <ntamayo-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:54:04 by ntamayo-          #+#    #+#              #
#    Updated: 2023/06/01 16:44:11 by ntamayo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CMPFILE	= ./srcs/docker-compose.yml

all: up

up:
	docker compose -f $(CMPFILE) up

recreate:
	docker compose -f $(CMPFILE) up --build --force-recreate

down:
	docker compose -f $(CMPFILE) down

clean:
	sudo rm -rf /home/ntamayo-/data/vol_wp/*
	sudo rm -rf /home/ntamayo-/data/vol_mdb/*

.PHONY: all clean down up recreate
