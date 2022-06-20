/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:52:46 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/20 18:48:39 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void static	texerror(t_program *mlx)
{
	if (!mlx->wllsprt.imptr
		|| !mlx->coinsprt.frame0 || !mlx->coinsprt.frame1
		|| !mlx->exitsprt.frame0 || !mlx->exitsprt.frame1
		|| !mlx->playsprt.frame0 || !mlx->playsprt.frame1)
		textureerror(&mlx->map, "Failed to load sprites.");
}

void	textureinit(t_program *mlx)
{
	mlx->xspsz = 80;
	mlx->yspsz = 80;
	mlx->wllsprt.imptr = mlx_xpm_file_to_image(mlx, "./sprites/Wall.xpm",
			&mlx->xspsz, &mlx->yspsz);
	mlx->coinsprt.frame0 = mlx_xpm_file_to_image(mlx, "./sprites/Collect.xpm",
			&mlx->xspsz, &mlx->yspsz);
	mlx->coinsprt.frame1 = mlx_xpm_file_to_image(mlx, "./sprites/Collect.xpm",
			&mlx->xspsz, &mlx->yspsz);
	mlx->exitsprt.frame0 = mlx_xpm_file_to_image(mlx, "./sprites/Egress.xpm",
			&mlx->xspsz, &mlx->yspsz);
	mlx->exitsprt.frame1 = mlx_xpm_file_to_image(mlx, "./sprites/Egress.xpm",
			&mlx->xspsz, &mlx->yspsz);
	mlx->playsprt.frame0 = mlx_xpm_file_to_image(mlx, "./sprites/Player.xpm",
			&mlx->xspsz, &mlx->yspsz);
	mlx->playsprt.frame1 = mlx_xpm_file_to_image(mlx, "./sprites/Player.xpm",
			&mlx->xspsz, &mlx->yspsz);
	texerror(mlx);
}
