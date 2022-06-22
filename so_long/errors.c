/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:50:35 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/22 11:19:48 by ntamayo-         ###   ########.fr       */
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

void	textureerror(t_program *mlx, char *msg)
{
	printf("Error\n%s", msg);
	imagedel(mlx);
	vanish_tiles(&mlx->map);
}
