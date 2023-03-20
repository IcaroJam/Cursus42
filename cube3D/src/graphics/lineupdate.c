/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineupdate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:27:42 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/20 16:11:09 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	scanline(t_vision_point *sight, mlx_image_t *line, t_cub *cub)
{
	int	h;
	int	start;
	int	end;

	(void)cub;
	h = WINHEIGHT / sight->distance;
	start = -h / 2 + WINHEIGHT / 2;
	if (start < 0)
		start = 0;
	end = h / 2 + WINHEIGHT / 2;
	if (end >= WINHEIGHT)
		end = WINHEIGHT - 1;
	printf("[h, s, e, d]: [%d, %d, %d, %f]\n", h, start, end, sight->distance);
	while (start < end)
	{
		mlx_put_pixel(line, 0, start, 0xFF0000FF);
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
		scanline(&cub->sight[i], cub->lines[i], cub);
		mlx_image_to_window(cub->mlx, cub->lines[i], i, 0);
		i++;
	}
}
