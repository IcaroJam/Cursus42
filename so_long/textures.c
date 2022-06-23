/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:52:46 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/23 13:59:30 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void static	texerror(t_program *mlx)
{
	if (!mlx->wllsprt.imptr || !mlx->bgsprt.imptr
		|| !mlx->winscreen.imptr || !mlx->deathscreen.imptr
		|| !mlx->black.imptr
		|| !mlx->foesprt.frame0 || !mlx->foesprt.frame1
		|| !mlx->coinsprt.frame0 || !mlx->coinsprt.frame1
		|| !mlx->exitsprt.frame0 || !mlx->exitsprt.frame1
		|| !mlx->playsprt.frame0 || !mlx->playsprt.frame1)
		textureerror(mlx, "Failed to load sprites.");
}

void static	solids(t_program *mlx)
{
	mlx->xspsz = 80;
	mlx->yspsz = 80;
	mlx->xscsz = 400;
	mlx->yscsz = 240;
	mlx->wllsprt.imptr = mlx_xpm_file_to_image(mlx->mlxptr,
			"./sprites/Wall.xpm", &mlx->xspsz, &mlx->yspsz);
	mlx->winscreen.imptr = mlx_xpm_file_to_image(mlx->mlxptr,
			"./sprites/Winscreen.xpm", &mlx->xscsz, &mlx->yscsz);
	mlx->deathscreen.imptr = mlx_xpm_file_to_image(mlx->mlxptr,
			"./sprites/Deathscreen.xpm", &mlx->xscsz, &mlx->yscsz);
	mlx->bgsprt.imptr = mlx_xpm_file_to_image(mlx->mlxptr,
			"./sprites/Back.xpm", &mlx->xspsz, &mlx->yspsz);
	mlx->black.imptr = mlx_xpm_file_to_image(mlx->mlxptr,
			"./sprites/Black.xpm", &mlx->xspsz, &mlx->yspsz);
}

void	textureinit(t_program *mlx)
{
	int	i;

	i = 0;
	solids(mlx);
	mlx->coinsprt.frame0 = mlx_xpm_file_to_image(mlx->mlxptr,
			"./sprites/Collect.xpm", &mlx->xspsz, &mlx->yspsz);
	mlx->coinsprt.frame1 = mlx_xpm_file_to_image(mlx->mlxptr,
			"./sprites/Collect1.xpm", &mlx->xspsz, &mlx->yspsz);
	mlx->exitsprt.frame0 = mlx_xpm_file_to_image(mlx->mlxptr,
			"./sprites/Egress.xpm", &mlx->xspsz, &mlx->yspsz);
	mlx->exitsprt.frame1 = mlx_xpm_file_to_image(mlx->mlxptr,
			"./sprites/Egress1.xpm", &mlx->xspsz, &mlx->yspsz);
	mlx->playsprt.frame0 = mlx_xpm_file_to_image(mlx->mlxptr,
			"./sprites/Player.xpm", &mlx->xspsz, &mlx->yspsz);
	mlx->playsprt.frame1 = mlx_xpm_file_to_image(mlx->mlxptr,
			"./sprites/Player1.xpm", &mlx->xspsz, &mlx->yspsz);
	mlx->foesprt.frame0 = mlx_xpm_file_to_image(mlx->mlxptr,
			"./sprites/Foe.xpm", &mlx->xspsz, &mlx->yspsz);
	mlx->foesprt.frame1 = mlx_xpm_file_to_image(mlx->mlxptr,
			"./sprites/Foe1.xpm", &mlx->xspsz, &mlx->yspsz);
	texerror(mlx);
	mlx->player.cursprt = mlx->playsprt.frame0;
	while (i < mlx->map.foes)
		mlx->foelst[i++].cursprt = mlx->foesprt.frame0;
	rendermap(mlx);
}
