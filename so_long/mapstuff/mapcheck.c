/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:30:50 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/23 13:25:17 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void static	charcheck(t_program *mlx, char c)
{
	if (!(c == '1' || c == '0' || c == 'C' || c == 'E'
			|| c == 'P' || c == 'B' || c == '\n'))
		printerror(mlx, "Map error: Illegal tile.");
}

void static	initialparse(int fd, t_program *mlx)
{
	char	temp;

	if (fd == -1)
		printerror(mlx, "Error while opening map file.");
	mlx->map.len = 0;
	mlx->map.clms = 0;
	mlx->map.rows = 0;
	mlx->map.collec = 0;
	mlx->map.egress = 0;
	mlx->map.plpos = 0;
	mlx->map.foes = 0;
	while (read(fd, &temp, 1) > 0)
	{
		charcheck(mlx, temp);
		mlx->map.len++;
		if (temp == '\n')
			mlx->map.rows++;
	}
}

void static	tilealloc(t_program *mlx)
{
	int	y;
	int	errvar;

	mlx->map.tile = malloc(sizeof(t_tile *) * (mlx->map.rows));
	if (!mlx->map.tile)
		printerror(mlx, "Failed to allocate memory for rows of tiles.");
	y = 0;
	while (y < mlx->map.rows)
	{
		mlx->map.tile[y] = malloc(sizeof(t_tile) * (mlx->map.clms));
		if (!mlx->map.tile[y])
		{
			errvar = 0;
			while (errvar++ < y)
				free(mlx->map.tile[errvar]);
			free(mlx->map.tile);
			free(mlx->map.str);
			printerror(mlx, "Failed to allocate memory for tiles.");
		}
		y++;
	}
}

void static	tiler(t_program *mlx)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	tilealloc(mlx);
	while (mlx->map.str[i])
	{
		x = 0;
		while (mlx->map.str[i] != '\n')
		{
			interactivity(mlx, i, x, y);
			mlx->map.tile[y][x].type = mlx->map.str[i++];
			mlx->map.tile[y][x++].update = 1;
		}
		i++;
		y++;
	}
}

void	premap(char *file, t_program *mlx)
{
	int		fd;

	fd = open(file, O_RDONLY);
	initialparse(fd, mlx);
	close(fd);
	mlx->map.str = malloc(sizeof(char) * (mlx->map.len + 1));
	if (!mlx->map.str)
		printerror(mlx, "Failed to allocate memory for map.str");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		maperror(mlx, "Error while reopening map file.");
	read(fd, mlx->map.str, mlx->map.len);
	mlx->map.str[mlx->map.len] = 0;
	close(fd);
	mapprocess(mlx);
	tiler(mlx);
}
