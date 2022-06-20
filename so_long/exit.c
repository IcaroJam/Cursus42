/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:31:10 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/20 13:13:42 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	vanish_tiles(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->rows)
		free(map->tile[y++]);
	free(map->tile);
	free(map->str);
	exit(0);
}

int	closer(void *program)
{
	vanish_tiles(&((t_program *)program)->map);
	return (0);
}
