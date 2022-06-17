/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheckII.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:58:14 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/17 11:59:59 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapprocess(t_map *map)
{
	int	irows;
	int	iclms;

	while (*map->str != '\n')
	{
		if (*map->str != '1')
			printerror("Map error: UPPER WALL BREACH!!!");
		map->str++;
		map->clms++;
	}
	map->str++;
	irows = 2;
	while (irows < map->rows)
	{
		iclms = 0;
		if (*map->str != '1')
			printerror("Map error: LEFT WALL BREACH!!!");
		while (*map->str != '\n')
		{
			map->str++;
			iclms++;
		}
		if (map->str[-1] != '1')
			printerror("Map error: RIGHT WALL BREACH!!!");
		if (iclms != map->clms)
			printerror("Map error: Wall shift???");
		map->str++;
		irows++;
	}
	iclms = 0;
	while (*map->str != '\n')
	{
		if (*map->str != '1')
			printerror("Map error: LOWER WALL BREACH!!!");
		map->str++;
		iclms++;
	}
	if (iclms != map->clms)
		printerror("Map error: Wall shift???");
}
