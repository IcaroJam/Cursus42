/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:30:50 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/20 20:02:01 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void static	charcheck(char c)
{
	if (!(c == '1' || c == '0' || c == 'C' || c == 'E'
			|| c == 'P' || c == 'B' || c == '\n'))
		printerror("Map error: Illegal tile.");
}

void static	initialparse(int fd, t_map *map)
{
	char	temp;

	if (fd == -1)
		printerror("Error while opening map file.");
	map->len = 0;
	map->clms = 0;
	map->rows = 0;
	map->collec = 0;
	map->egress = 0;
	map->plpos = 0;
	while (read(fd, &temp, 1) > 0)
	{
		charcheck(temp);
		map->len++;
		if (temp == '\n')
			map->rows++;
	}
}

void static	tilealloc(t_map *map)
{
	int	y;
	int	errvar;

	map->tile = malloc(sizeof(t_tile *) * (map->rows));
	if (!map->tile)
		printerror("Failed to allocate memory for a row of tiles.");
	y = 0;
	while (y < map->rows)
	{
		map->tile[y] = malloc(sizeof(t_tile) * (map->clms));
		if (!map->tile[y])
		{
			errvar = 0;
			while (errvar++ < y)
				free(map->tile[errvar]);
			free(map->tile);
			free(map->str);
			printerror("Failed to allocate memory for the tiles of a row.");
		}
		y++;
	}
}

void static	tiler(t_map *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	tilealloc(map);
	while (map->str[i])
	{
		x = 0;
		while (map->str[i] != '\n')
		{
			map->tile[y][x].type = map->str[i++];
			map->tile[y][x++].update = 1;
		}
		i++;
		y++;
	}
}

void	premap(char *file, t_map *map)
{
	int		fd;

	fd = open(file, O_RDONLY);
	initialparse(fd, map);
	close(fd);
	map->str = malloc(sizeof(char) * (map->len + 1));
	if (!map->str)
		printerror("Failed to allocate memory for map->str.");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		maperror(map, "Error while reopening map file.");
	read(fd, map->str, map->len);
	map->str[map->len] = 0;
	close(fd);
	mapprocess(map);
	tiler(map);
}
