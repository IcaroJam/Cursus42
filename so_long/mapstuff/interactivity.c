/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactivity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:07:47 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/23 16:04:39 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	interactivity(t_program *mlx, int i, int x, int y)
{
	if (mlx->map.str[i] == 'P')
	{
		mlx->player.xpos = x;
		mlx->player.ypos = y;
	}
	else if (mlx->map.str[i] == 'B')
	{
		mlx->foelst[mlx->foecount].xpos = x;
		mlx->foelst[mlx->foecount].ypos = y;
		if (x > y)
			mlx->foelst[mlx->foecount].direction = -1;
		else
			mlx->foelst[mlx->foecount].direction = 1;
		mlx->foecount++;
	}
	else if (mlx->map.str[i] == 'C')
		mlx->map.tile[y][x].interacted = 0;
	else if (mlx->map.str[i] == 'E')
		mlx->map.tile[y][x].interacted = 0;
}
