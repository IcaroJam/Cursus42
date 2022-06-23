/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactivity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:07:47 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/23 13:42:41 by ntamayo-         ###   ########.fr       */
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
		mlx->foelst->xpos = x;
		mlx->foelst->ypos = y;
		if (x > y)
			mlx->foelst->direction = 0;
		else
			mlx->foelst->direction = 1;
		mlx->foelst++;
	}
	else if (mlx->map.str[i] == 'C')
		mlx->map.tile[y][x].interacted = 0;
	else if (mlx->map.str[i] == 'E')
		mlx->map.tile[y][x].interacted = 0;
}
