/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsetextures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:17:21 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/07 17:51:31 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static int	texlen(char *line)
{
	int	ret;

	ret = 0;
	while(line[ret] > 32 && line[ret] < 127)
		ret++;
	return (ret);
}

static char	**gettexptr(char *line, t_cub *cub)
{
	char	**texturedir;

	if (!ft_strncmp(line, "NO", 2))
		texturedir = &cub->mdata.npath;
	else if(!ft_strncmp(line, "SO", 2))
		texturedir = &cub->mdata.spath;
	else if(!ft_strncmp(line, "WE", 2))
		texturedir = &cub->mdata.wpath;
	else if(!ft_strncmp(line, "EA", 2))
		texturedir = &cub->mdata.epath;
	else
	{
		errmsg("Bad texture identifier. Accepted: [NO, WE, SO, EA].");
		exit(1);
	}
	return (texturedir);
}

static void	texstore(char *line, t_cub *cub)
{
	char **texturedir;

	while (ft_isspace(*line))
		line++;
	if (!*line)
		return ;
	texturedir = gettexptr(line, cub);
	line += 2;
	while (ft_isspace(*line))
		line++;
	*texturedir = ft_substr(line, 0, texlen(line));
	if (!*texturedir)
	{
		errmsg("Failed to copy a texture path.");
		exit(1);
	}
}

void	gettextures(int fd, t_cub *cub)
{
	int		texcount;
	char	*temp;

	texcount = 0;
	while (texcount < 3)
	{
		temp = get_next_line(fd);
		if (!temp)
		{
			errmsg("Map reading failed!");
			exit(1);
		}
		texstore(temp, cub);
		free(temp);
		texcount++;
	}
	printf("NO: [%s]\nWE: [%s]\nSO: [%s]\nEA: [%s]\n", cub->mdata.npath, cub->mdata.wpath, cub->mdata.spath, cub->mdata.epath);
}
