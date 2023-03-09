/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:07:06 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/09 12:04:25 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void	handleinputandinit(int argc, char **argv, t_cub *cub)
{
	if (argc == 1)
		errexit("Missing map. Usage: [./cube3D <<mapname>>.cub]");
	else if (argc > 2)
		errexit("Too many input arguments. Usage: [./cube3D <<mapname>>.cub]");
	if (filecheck(argv[1], ft_strlen(argv[1])) == -1)
		errexit("Invalid map format. Usage: [./cube3D <<mapname>>.cub]");
	cub->mdata.cmap = NULL;
	cub->mdata.npath = NULL;
	cub->mdata.wpath = NULL;
	cub->mdata.spath = NULL;
	cub->mdata.epath = NULL;
}

void	leakcheck(void)
{
	system("leaks cube3D");
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	atexit(leakcheck);
	handleinputandinit(argc, argv, &cub);
	parsemap(argv[1], &cub);
	freecub(&cub);
	return (0);
}
