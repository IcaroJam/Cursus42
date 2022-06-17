/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheckII.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:58:14 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/17 12:25:52 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void static	top(t_map *map)
{
	while (*map->str != '\n')
	{
		if (*map->str != '1')
			printerror("Map error: UPPER WALL BREACH!!!");
		map->str++;
		map->clms++;
	}
}

void static	bottom(t_map *map, int	*iclms)
{
	while (*map->str != '\n')
	{
		if (*map->str != '1')
			printerror("Map error: LOWER WALL BREACH!!!");
		map->str++;
		(*iclms)++;
	}
}

void static	midrows(t_map *map, int	*irows, int *iclms)
{
	while (*irows < map->rows)
	{
		*iclms = 0;
		if (*map->str != '1')
			printerror("Map error: LEFT WALL BREACH!!!");
		while (*map->str != '\n')
		{
			map->str++;
			(*iclms)++;
		}
		if (map->str[-1] != '1')
			printerror("Map error: RIGHT WALL BREACH!!!");
		if (*iclms != map->clms)
			printerror("Map error: Wall shift???");
		map->str++;
		(*irows)++;
	}
}

void	mapprocess(t_map *map)
{
	int		irows;
	int		iclms;
	char	*originalstr;

	originalstr = map->str;
	top(map);
	map->str++;
	irows = 2;
	midrows(map, &irows, &iclms);
	iclms = 0;
	bottom(map, &iclms);
	if (iclms != map->clms)
		printerror("Map error: Wall shift???");
	map->str = originalstr;
}
