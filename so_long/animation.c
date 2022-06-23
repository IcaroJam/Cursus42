/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:48:35 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/23 15:33:13 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void static	playeranim(t_program *mlx)
{
	if (mlx->player.cursprt == mlx->playsprt.frame0)
		mlx->player.cursprt = mlx->playsprt.frame1;
	else
		mlx->player.cursprt = mlx->playsprt.frame0;
	mlx->map.tile[mlx->player.ypos][mlx->player.xpos].update = 1;
}

void static	foeanim(t_program *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map.foes)
	{
		if (mlx->foelst[i].cursprt == mlx->foesprt.frame0)
			mlx->foelst[i].cursprt = mlx->foesprt.frame1;
		else
			mlx->foelst[i].cursprt = mlx->foesprt.frame0;
		mlx->map.tile[mlx->foelst[i].ypos][mlx->foelst[i].xpos].update = 1;
		i++;
	}
}

int	animate(void *program)
{
	t_program	*mlx;

	mlx = program;
	if (mlx->player.isdead || mlx->player.won)
		return (1);
	if (mlx->frame == 3599)
	{
		playeranim(mlx);
		foeanim(mlx);
		rendermap(mlx);
	}
	mlx->frame++;
	if (mlx->frame == 3600)
		mlx->frame = 0;
	return (0);
}
