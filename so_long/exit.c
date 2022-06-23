/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:31:10 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/23 11:04:43 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vanish_tiles(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->rows)
	{
		free(map->tile[y]);
		map->tile[y++] = NULL;
	}
	free(map->tile);
	map->tile = NULL;
	free(map->str);
	map->str = NULL;
}

void	imagedel(t_program *mlx)
{
	mlx_destroy_image(mlx->mlxptr, mlx->wllsprt.imptr);
	mlx_destroy_image(mlx->mlxptr, mlx->bgsprt.imptr);
	mlx_destroy_image(mlx->mlxptr, mlx->black.imptr);
	mlx_destroy_image(mlx->mlxptr, mlx->deathscreen.imptr);
	mlx_destroy_image(mlx->mlxptr, mlx->winscreen.imptr);
	mlx_destroy_image(mlx->mlxptr, mlx->coinsprt.frame0);
	mlx_destroy_image(mlx->mlxptr, mlx->coinsprt.frame1);
	mlx_destroy_image(mlx->mlxptr, mlx->exitsprt.frame0);
	mlx_destroy_image(mlx->mlxptr, mlx->exitsprt.frame1);
	mlx_destroy_image(mlx->mlxptr, mlx->playsprt.frame0);
	mlx_destroy_image(mlx->mlxptr, mlx->playsprt.frame1);
}

int	closer(void *program)
{
	t_program	*mlx;

	mlx = program;
	imagedel(mlx);
	vanish_tiles(&mlx->map);
	mlx_destroy_window(mlx->mlxptr, mlx->winptr);
	free(mlx->mlxptr);
	exit(0);
	return (0);
}
