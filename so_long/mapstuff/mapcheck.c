/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:30:50 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/17 20:41:10 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void static	charcheck(char c)
{
	if (!(c == '1' || c == '0' || c == 'C' || c == 'E'
			|| c == 'P' || c == '\n'))
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
		printerror("Error while reopening map file.");
	read(fd, map->str, map->len);
	close(fd);
	mapprocess(map);
}
