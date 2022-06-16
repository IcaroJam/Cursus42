/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:30:50 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/16 16:40:34 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void static	charcheck(char c)
{
	if (!(c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P' || c == '\n'))
		printerror("Map error: Illegal tile.");
}

void static	mapprocess(t_map *map)
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
	iclms = 1;
	irows = 2;
	while (irows < map->rows)
	{
		if (*map->str != '1')
			printerror("Map error: LEFT WALL BREACH!!!");
		map->str++;
		while (map->str[1] != '\n')
		{
			map->str++;
			iclms++;
		}
		if (*map->str != '1')
			printerror("Map error: RIGHT WALL BREACH!!!");
		if (iclms != map->clms)
			printerror("Map error: Wall shift???");
	}
}

void	premap(char *file, t_map *map)
{
	int		fd;
	char	temp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		printerror("Error while opening map file.");
	map->len = 0;
	map->clms = 0;
	map->rows = 0;
	while (read(fd, &temp, 1) > 0)
	{
		charcheck(temp);
		map->len++;
		if (temp == '\n')
			map->rows++;
	}
	close(fd);
	map->str = malloc(sizeof(char) * (map->len + 1));
	if (!map->str)
		printerror("Failed to allocate memory for map->str.");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		printerror("Error while reopening map file.");
	read(fd, map->str, map->len);
	close(fd);
	mapprocess(map);
}
