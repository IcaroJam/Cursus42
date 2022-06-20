/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheckII.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:58:14 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/20 13:13:23 by ntamayo-         ###   ########.fr       */
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

void static	top(t_map *map, int *i)
{
	while (map->str[*i] != '\n')
	{
		if (map->str[*i] != '1')
			maperror(map, "Map error: UPPER WALL BREACH!!!");
		(*i)++;
		map->clms++;
	}
}

void static	bottom(t_map *map, int	*iclms, int *i)
{
	while (map->str[*i] != '\n')
	{
		if (map->str[*i] != '1')
			maperror(map, "Map error: LOWER WALL BREACH!!!");
		(*i)++;
		(*iclms)++;
	}
}

void static	midrows(t_map *map, int	*irows, int *iclms, int *i)
{
	while (*irows < map->rows)
	{
		*iclms = 0;
		if (map->str[*i] != '1')
			maperror(map, "Map error: LEFT WALL BREACH!!!");
		while (map->str[*i] != '\n')
		{
			stuffcount(map, map->str[*i]);
			(*i)++;
			(*iclms)++;
		}
		if (map->str[*i - 1] != '1')
			maperror(map, "Map error: RIGHT WALL BREACH!!!");
		if (*iclms != map->clms)
			maperror(map, "Map error: Wall shift???");
		(*i)++;
		(*irows)++;
	}
}

void	mapprocess(t_map *map)
{
	int	irows;
	int	iclms;
	int	i;

	i = 0;
	top(map, &i);
	i++;
	irows = 2;
	midrows(map, &irows, &iclms, &i);
	iclms = 0;
	bottom(map, &iclms, &i);
	if (iclms != map->clms)
		maperror(map, "Map error: Wall shift???");
	if (map->plpos == 0)
		maperror(map, "Map error: Player not found!");
	if (map->plpos > 1)
		maperror(map, "Map error: No doppelgangers allowed!");
	if (map->collec == 0)
		maperror(map, "Map error: It's a sad world without collectibles...");
	if (map->egress == 0)
		maperror(map, "Map error: There is no escape...");
}
