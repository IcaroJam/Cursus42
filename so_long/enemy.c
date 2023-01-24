/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:02:15 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/24 10:44:56 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	getfoenewpos(t_map *map, t_foe *foe)
{
	int	ret;

	if (map->tile[foe->ypos][foe->xpos + foe->direction].type != '0'
		&& map->tile[foe->ypos][foe->xpos + foe->direction].type != 'P')
	{
		foe->direction *= -1;
	}
	ret = foe->xpos + foe->direction;
	return (ret);
}

static void	foelogic(t_map *map, t_foe *foe, t_player *player)
{
	int	xto;
	int	yto;

	xto = getfoenewpos(map, foe);
	yto = foe->ypos;
	if (map->tile[yto][xto].type == 'P')
		player->isdead = 1;
	if (map->tile[yto][xto].type == '0' || map->tile[yto][xto].type == 'P')
	{
		map->tile[yto][xto].type = 'B';
		map->tile[foe->ypos][foe->xpos].type = '0';
		map->tile[yto][xto].update = 1;
		map->tile[foe->ypos][foe->xpos].update = 1;
		foe->xpos = xto;
		foe->ypos = yto;
	}
}

void	foeia(t_program *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map.foes)
		foelogic(&mlx->map, &mlx->foelst[i++], &mlx->player);
}
