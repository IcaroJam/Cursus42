/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineupdate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:27:42 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/23 15:19:41 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static unsigned int	texturer(mlx_image_t *img, int lineh, int j, float texcoord)
{
	const uint_fast32_t	*px = (uint_fast32_t *)img->pixels;
	unsigned int		hex;
	const float			step = img->height / (float)lineh;
	int					pixindex;

	hex = 0;
	pixindex = (img->width * (int)(j * step) + (int)(img->width * texcoord));
	hex |= (px[pixindex] & 0xff000000) >> 24;
	hex |= (px[pixindex] & 0x00ff0000) >> 8;
	hex |= (px[pixindex] & 0x0000ff00) << 8;
	hex |= (px[pixindex] & 0x000000ff) << 24;
	return (hex);
}

static void	scanline(t_cub *cub, unsigned int i)
{
	int	j;
	int	h;
	int	start;
	int	end;

	h = WINHEIGHT / cub->sight[i].dist;
	start = -h / 2 + WINHEIGHT / 2;
	end = h / 2 + WINHEIGHT / 2;
	if (end >= WINHEIGHT)
		end = WINHEIGHT;
	j = 0;
	while (j < start)
		mlx_put_pixel(cub->lines[i], 0, j++, 0);
	while (j < end)
	{
		if (cub->sight[i].worient == -1)
			mlx_put_pixel(cub->lines[i], 0, j, texturer(cub->simg, h, j - start, cub->sight[i].wtexc));
		else if (cub->sight[i].worient == 0)
			mlx_put_pixel(cub->lines[i], 0, j, texturer(cub->eimg, h, j - start, cub->sight[i].wtexc));
		else if (cub->sight[i].worient == 2)
			mlx_put_pixel(cub->lines[i], 0, j, texturer(cub->wimg, h, j - start, cub->sight[i].wtexc));
		else
		    mlx_put_pixel(cub->lines[i], 0, j, texturer(cub->nimg, h, j - start, cub->sight[i].wtexc));
		/** if (cub->sight[i].worient == -1)
		  *     mlx_put_pixel(cub->lines[i], 0, j, 0x997070FF);
		  * else if (cub->sight[i].worient == 0)
		  *     mlx_put_pixel(cub->lines[i], 0, j, 0x997070FF);
		  * else if (cub->sight[i].worient == 2)
		  *     mlx_put_pixel(cub->lines[i], 0, j, 0x997070FF);
		  * else
		  *     mlx_put_pixel(cub->lines[i], 0, j, 0x997070FF); */
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
