/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:50:35 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/20 18:02:38 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printerror(char *msg)
{
	printf("Error\n%s", msg);
	exit(1);
}

void	maperror(t_map *map, char *msg)
{
	free(map->str);
	printerror(msg);
}

void	textureerror(t_map *map, char *msg)
{
	printf("Error\n%s", msg);
	vanish_tiles(map);
}
