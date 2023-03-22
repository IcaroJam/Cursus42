/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineupdate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:27:42 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/22 11:43:19 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	scanline(t_cub *cub, unsigned int i)
{
	int	j;
	int	h;
	int	start;
	int	end;

	h = WINHEIGHT / cub->sight[i].distance;
	start = -h / 2 + WINHEIGHT / 2;
	if (start < 0)
		start = 0;
	end = h / 2 + WINHEIGHT / 2;
	if (end >= WINHEIGHT)
		end = WINHEIGHT - 1;
	j = 0;
	while (j < start)
		mlx_put_pixel(cub->lines[i], 0, j++, 0);
	while (j < end)
	{
		if (cub->sight[i].wall_orientation == -1)
			mlx_put_pixel(cub->lines[i], 0, j, 0x995050FF);
		else if (cub->sight[i].wall_orientation == 0)
			mlx_put_pixel(cub->lines[i], 0, j, 0x509950FF);
		else if (cub->sight[i].wall_orientation == 2)
			mlx_put_pixel(cub->lines[i], 0, j, 0x505099FF);
		else
			mlx_put_pixel(cub->lines[i], 0, j, 0x999950FF);
		j++;
	}
	while (j < WINHEIGHT)
		mlx_put_pixel(cub->lines[i], 0, j++, 0);
}

void	lineupdate(t_cub *cub)
{
	unsigned int	i;

	i = 0;
	ft_raycasting(cub);
	while (i < WINWIDTH)
	{
		scanline(cub, i);
		i++;
	}
}
