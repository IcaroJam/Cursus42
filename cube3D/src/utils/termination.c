/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:27:33 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/12 18:15:48 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	errmsg(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
}

void	errexit(char *msg)
{
	errmsg(msg);
	exit(1);
}

void	freecub(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->mdata.cmap && cub->mdata.cmap[i])
		free(cub->mdata.cmap[i++]);
	free(cub->mdata.cmap);
	free(cub->mdata.npath);
	free(cub->mdata.wpath);
	free(cub->mdata.spath);
	free(cub->mdata.epath);
	if (cub->mlx)
		mlx_terminate(cub->mlx);
}

void	frerrxit(char *msg, t_cub *cub)
{
	freecub(cub);
	errexit(msg);
}
