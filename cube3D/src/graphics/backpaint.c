/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backpaint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:02:49 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/20 12:14:25 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	backpaint(t_cub *cub)
{
	unsigned int		i;
	unsigned int		j;
	const unsigned int	halfheight = WINHEIGHT / 2;

	cub->back = mlx_new_image(cub->mlx, WINWIDTH, WINHEIGHT);
	if (!cub->back)
		frerrxit("Failed to load sky and earth.", cub);
	j = 0;
	while (j < WINHEIGHT)
	{
		i = 0;
		while (i < WINWIDTH)
		{
			if (j < halfheight)
				mlx_put_pixel(cub->back, i, j, cub->mdata.ceilic);
			else
				mlx_put_pixel(cub->back, i, j, cub->mdata.floorc);
			i++;
		}
		j++;
	}
	mlx_image_to_window(cub->mlx, cub->back, 0, 0);
}
