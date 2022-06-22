/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:52:46 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/22 13:04:33 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void static	texerror(t_program *mlx)
{
	if (!mlx->wllsprt.imptr || !mlx->bgsprt.imptr
		|| !mlx->coinsprt.frame0 || !mlx->coinsprt.frame1
		|| !mlx->exitsprt.frame0 || !mlx->exitsprt.frame1
		|| !mlx->playsprt.frame0 || !mlx->playsprt.frame1)
		textureerror(mlx, "Failed to load sprites.");
}

void	textureinit(t_program *mlx)
{
	mlx->xspsz = 80;
	mlx->yspsz = 80;
	mlx->wllsprt.imptr = mlx_xpm_file_to_image(mlx->mlxptr, "./sprites/Wall.xpm",
			&mlx->xspsz, &mlx->yspsz);
	mlx->bgsprt.imptr = mlx_xpm_file_to_image(mlx->mlxptr, "./sprites/Back.xpm",
			&mlx->xspsz, &mlx->yspsz);
	mlx->coinsprt.frame0 = mlx_xpm_file_to_image(mlx->mlxptr, "./sprites/Collect.xpm",
			&mlx->xspsz, &mlx->yspsz);
	mlx->coinsprt.frame1 = mlx_xpm_file_to_image(mlx->mlxptr, "./sprites/Collect.xpm",
			&mlx->xspsz, &mlx->yspsz);
	mlx->exitsprt.frame0 = mlx_xpm_file_to_image(mlx->mlxptr, "./sprites/Egress.xpm",
			&mlx->xspsz, &mlx->yspsz);
	mlx->exitsprt.frame1 = mlx_xpm_file_to_image(mlx->mlxptr, "./sprites/Egress.xpm",
			&mlx->xspsz, &mlx->yspsz);
	mlx->playsprt.frame0 = mlx_xpm_file_to_image(mlx->mlxptr, "./sprites/Player.xpm",
			&mlx->xspsz, &mlx->yspsz);
	mlx->playsprt.frame1 = mlx_xpm_file_to_image(mlx->mlxptr, "./sprites/Player1.xpm",
			&mlx->xspsz, &mlx->yspsz);
	texerror(mlx);
	mlx->player.currsprite = mlx->playsprt.frame0;
	rendermap(mlx);
}
