/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:48:35 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/23 11:23:45 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animate(void *program)
{
	t_program	*mlx;

	mlx = program;
	if (mlx->player.isdead || mlx->player.won)
		return (1);
	if (mlx->frame == 3599)
	{
		if (mlx->player.cursprt == mlx->playsprt.frame0)
			mlx->player.cursprt = mlx->playsprt.frame1;
		else
			mlx->player.cursprt = mlx->playsprt.frame0;
		mlx->map.tile[mlx->player.ypos][mlx->player.xpos].update = 1;
		rendermap(mlx);
	}
	mlx->frame++;
	if (mlx->frame == 3600)
		mlx->frame = 0;
	return (0);
}
