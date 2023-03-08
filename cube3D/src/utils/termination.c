/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:27:33 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/08 15:39:36 by ntamayo-         ###   ########.fr       */
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
	free(cub->mdata.npath);
	free(cub->mdata.wpath);
	free(cub->mdata.spath);
	free(cub->mdata.epath);
}

void	frerrxit(char *msg, t_cub *cub)
{
	freecub(cub);
	errexit(msg);
}
