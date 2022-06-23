/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:02:15 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/23 17:39:46 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	foeia(t_program *mlx)
{
	int	i;
	int	xto;
	int	yto;

	i = 0;
	while (i < mlx->map.foes)
	{
		xto = mlx->foelst[i].xpos + mlx->foelst[i].direction;
		yto = mlx->foelst[i].ypos;
		if (mlx->map.tile[yto][xto].type == 'P')
			mlx->player.isdead = 1;
		else if (mlx->map.tile[yto][xto].type != '0')
		{
			mlx->foelst[i].direction *= -1;
			xto = mlx->foelst[i].xpos + mlx->foelst[i].direction;
			yto = mlx->foelst[i].ypos;
		}
		mlx->map.tile[yto][xto].type = 'B';
		mlx->map.tile[mlx->foelst[i].ypos][mlx->foelst[i].xpos].type = '0';
		mlx->map.tile[yto][xto].update = 1;
		mlx->map.tile[mlx->foelst[i].ypos][mlx->foelst[i].xpos].update = 1;
		mlx->foelst[i].xpos = xto;
		mlx->foelst[i].ypos = yto;
		i++;
	}
}
