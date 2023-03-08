/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:40:33 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/08 15:32:43 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"
#include <fcntl.h>
#include <unistd.h>

static int	openmap(char *mapfile)
{
	int	fd;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		errexit("Unable to open provided map file.");
	return (fd);
}

static void	getconfig(int fd, t_cub *cub)
{
	char	*temp;
	int		colstored[2];

	colstored[0] = 0;
	colstored[1] = 0;
	cub->mdata.npath = NULL;
	cub->mdata.wpath = NULL;
	cub->mdata.spath = NULL;
	cub->mdata.epath = NULL;
	while (!colstored[0] || !colstored[1]
		|| !cub->mdata.npath || !cub->mdata.spath
		|| !cub->mdata.epath || !cub->mdata.wpath)
	{
		temp = get_next_line(fd);
		if (!temp)
			frerrxit("Map reading failed! Or not all fields are present.", cub);
		if (gettextures(temp, cub))
			getcolours(colstored, temp, cub);
		free(temp);
	}
	printf("NO: [%s]\nWE: [%s]\nSO: [%s]\nEA: [%s]\nF: [%x]\nC: [%x]\n", cub->mdata.npath, cub->mdata.wpath, cub->mdata.spath, cub->mdata.epath, cub->mdata.floorc, cub->mdata.ceilic);
}

static void	getmap(int fd, t_cub *cub)
{
	
}

void	parsemap(char *mapfile, t_cub *cub)
{
	int	fd;

	fd = openmap(mapfile);
	getconfig(fd, cub);
	close(fd);
}
