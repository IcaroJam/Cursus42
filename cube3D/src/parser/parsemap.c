/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:40:33 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/07 17:18:17 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"
#include <fcntl.h>

static int	openmap(char *mapfile)
{
	int	fd;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
	{
		errmsg("Unable to open provided map file.");
		exit(1);
	}
	return (fd);
}

void	parsemap(char *mapfile, t_cub *cub)
{
	int	fd;
	
	fd = openmap(mapfile);
	gettextures(fd, cub);
}
