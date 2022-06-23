/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keystroked.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:13:42 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/23 10:29:16 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void static	playerupdate(t_program *mlx, int xto, int yto)
{
	mlx->map.tile[mlx->player.ypos][mlx->player.xpos].type = '0';
	mlx->map.tile[mlx->player.ypos][mlx->player.xpos].update = 1;
	if (mlx->map.tile[yto][xto].type != 'E')
	{
		mlx->map.tile[yto][xto].type = 'P';
		mlx->player.xpos = xto;
		mlx->player.ypos = yto;
	}
	else
		mlx->player.isdead = 1;
	mlx->map.tile[yto][xto].interacted = 1;
	mlx->map.tile[yto][xto].update = 1;
	ft_printf("Moves: %d\n", ++mlx->player.moves);
}

void static	playermove(int xto, int yto, t_program *mlx)
{
	if (mlx->map.tile[yto][xto].type == '0')
		playerupdate(mlx, xto, yto);
	else if (mlx->map.tile[yto][xto].type == 'C')
	{
		if (mlx->map.tile[yto][xto].interacted)
			playerupdate(mlx, xto, yto);
		else
		{
			mlx->map.tile[yto][xto].interacted = 1;
			mlx->map.tile[yto][xto].update = 1;
			mlx->player.collectedcoins++;
		}
	}
	else if (mlx->map.tile[yto][xto].type == 'E'
			&& mlx->player.collectedcoins == mlx->map.collec)
		playerupdate(mlx, xto, yto);
}

int	keystroked(int key, void *program)
{
	t_program	*mlx;

	mlx = program;
	if (key == 53)
		closer(program);
	else if (mlx->player.isdead)
		return (1);
	else if (key == 0)
		playermove(mlx->player.xpos - 1, mlx->player.ypos, mlx);
	else if (key == 1)
		playermove(mlx->player.xpos, mlx->player.ypos + 1, mlx);
	else if (key == 2)
		playermove(mlx->player.xpos + 1, mlx->player.ypos, mlx);
	else if (key == 13)
		playermove(mlx->player.xpos, mlx->player.ypos - 1, mlx);
	rendermap(mlx);
	return (0);
}
