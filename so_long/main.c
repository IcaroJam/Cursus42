/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:47:12 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/16 16:09:53 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>

int static	check_extension(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	len--;
	if (argv[len--] == 'r')
		if (argv[len--] == 'e')
			if (argv[len--] == 'b')
				if (argv[len] == '.')
					return (0);
	return (1);
}

void static	inputhandler(int argc, char *argv)
{
	if (argc != 2)
		printerror("Wrong number of arguments.");
	if (check_extension(argv))
		printerror("Wrong map file extension.");
}

void static	premap(char *file, t_map *map)
{
	int		fd;
	char	temp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		printerror("Error while opening map file.");
	map->len = 0;
	while (read(fd, &temp, 1) > 0)
		map->len++;
	close(fd);
	map->str = malloc(sizeof(char) * (map->len + 1));
	if (!map->str)
		printerror("Failed to allocate memory for map->str.");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		printerror("Error while reopening map file.");
	read(fd, map->str, map->len);
	close(fd);
}

int	main(int argc, char **argv)
{
	//t_program	mlx;
	t_map	map;

	inputhandler(argc, argv[1]);
	premap(argv[1], &map);
	//mlx.mlxptr = mlx_init();
	//if (!mlx.mlxptr)
	//	return (1);
	//mlx.winptr = mlx_new_window(mlx.mlxptr, WINWIDTH, WINHEIGHT, "ThisIsATest B)");
	//mlx_loop(mlx.mlxptr);
	return (0);
}
