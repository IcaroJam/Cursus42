/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keystroked.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:13:42 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/22 18:02:17 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void static	playerupdate(t_program *mlx, int xto, int yto)
{
	mlx->map.tile[mlx->player.ypos][mlx->player.xpos].type = '0';
	mlx->map.tile[yto][xto].type = 'P';
	mlx->map.tile[mlx->player.ypos][mlx->player.xpos].update = 1;
	mlx->map.tile[yto][xto].update = 1;
	mlx->player.xpos = xto;
	mlx->player.ypos = yto;
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
	{
		mlx->map.tile[mlx->player.ypos][mlx->player.xpos].type = '0';
		mlx->map.tile[yto][xto].interacted = 1;
		mlx->map.tile[yto][xto].update = 1;
		mlx->map.tile[mlx->player.ypos][mlx->player.xpos].update = 1;
		mlx->player.isdead = 1;
		ft_printf("Moves: %d\n", ++mlx->player.moves);
	}
	rendermap(mlx);
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
	return (0);
}
