/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeitsquared.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:16:12 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/09 11:41:33 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static unsigned int	getmaxlen(char **map)
{
	unsigned int	ret;
	unsigned int	temp;

	ret = 0;
	while (*map)
	{
		temp = 0;
		while (map[0][temp])
			temp++;
		if (temp > ret)
			ret = temp;
		map++;
	}
	return (ret);
}

static void	stretchlines(t_cub *cub)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	while (cub->mdata.cmap[i])
	{
		while (ft_strlen(cub->mdata.cmap[i]) < cub->mdata.xsize)
		{
			temp = ft_strjoin(cub->mdata.cmap[i], " ");
			if (!temp)
				frerrxit("Map stretching failed!", cub);
			free(cub->mdata.cmap[i]);
			cub->mdata.cmap[i] = temp;
		}
		i++;
	}
}

void	makeitsquared(t_cub *cub)
{
	cub->mdata.ysize = 0;
	while (cub->mdata.cmap[cub->mdata.ysize])
		cub->mdata.ysize++;
	cub->mdata.xsize = getmaxlen(cub->mdata.cmap);
	stretchlines(cub);
}
