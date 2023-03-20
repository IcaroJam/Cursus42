/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineupdate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:27:42 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/20 17:04:12 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	scanline(t_cub *cub, unsigned int i)
{
	int	h;
	int	start;
	int	end;

	(void)cub;
	h = WINHEIGHT / cub->sight[i].distance;
	start = -h / 2 + WINHEIGHT / 2;
	if (start < 0)
		start = 0;
	end = h / 2 + WINHEIGHT / 2;
	if (end >= WINHEIGHT)
		end = WINHEIGHT - 1;
	while (start < end)
	{
		mlx_put_pixel(cub->lines[i], 0, start, 0xFF0000FF);
		start++;
	}
}

void	lineupdate(t_cub *cub)
{
	unsigned int	i;

	i = 0;
	ft_raycasting(cub);
	while (i < WINWIDTH)
	{
		scanline(cub, i);
		mlx_image_to_window(cub->mlx, cub->lines[i], i, 0);
		i++;
	}
}
