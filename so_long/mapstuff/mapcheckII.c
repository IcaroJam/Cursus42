/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheckII.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:58:14 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/18 16:40:32 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void static	stuffcount(t_map *map, char c)
{
	if (c == 'C')
		map->collec++;
	else if (c == 'E')
		map->egress++;
	else if (c == 'P')
		map->plpos++;
}

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
			stuffcount(map, *map->str);
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
	if (map->plpos == 0)
		printerror("Map error: Player not found!");
	if (map->plpos > 1)
		printerror("Map error: No doppelgangers allowed!");
	if (map->collec == 0)
		printerror("Map error: It's a sad world without collectibles...");
	if (map->egress == 0)
		printerror("Map error: There is no escape...");
	map->str = originalstr;
}
