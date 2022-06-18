/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:31:10 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/18 20:08:31 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vanish_tiles(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->rows)
		free(map->tile[y++]);
	free(map->tile);
	exit(0);
}

int	closer(void *program)
{
	vanish_tiles(&((t_program *)program)->map);
	return (0);
}
