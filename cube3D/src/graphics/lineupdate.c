/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineupdate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:27:42 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/23 16:33:30 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static unsigned int	texturer(mlx_texture_t *tex, int j, int texcrd, float stp)
{
	/** const uint_fast32_t	*px = (uint_fast32_t *)tex->pixels; */
	unsigned int		hex;
	int					pixindex;

	hex = 0;
	pixindex = 4 * (tex->width * (int)(j * stp) + texcrd);
	/** pixindex = (tex->width * (int)(j * stp) + texcrd); */
	/** hex |= (px[pixindex] & 0xff000000) >> 24;
	  * hex |= (px[pixindex] & 0x00ff0000) >> 8;
	  * hex |= (px[pixindex] & 0x0000ff00) << 8;
	  * hex |= (px[pixindex] & 0x000000ff) << 24; */
	hex = (tex->pixels[pixindex] << 24) | (tex->pixels[pixindex + 1] << 16) | (tex->pixels[pixindex + 2] << 8) | (tex->pixels[pixindex + 3]);
	return (hex);
}

// Optimization (and specially the norm) made this one really fucking ugly,
// but hey, it works.
static void	scanline(t_cub *cub, mlx_texture_t *tex, unsigned int i)
{
	int		j;
	int		h;
	int		start;
	int		end;
	float	coordstep[2];

	h = WINHEIGHT / cub->sight[i].dist;
	start = -h * 0.5 + WINHEIGHT * 0.5 ;
	end = h * 0.5 + WINHEIGHT * 0.5;
	if (end >= WINHEIGHT)
		end = WINHEIGHT;
	coordstep[0] = tex->width * cub->sight[i].wtexc;
	coordstep[1] = tex->height / (float)h;
	j = 0;
	(void)tex;
	while (j < start)
		mlx_put_pixel(cub->lines, i, j++, 0);
	while (j < end)
	{
		mlx_put_pixel(cub->lines, i, j, texturer(tex,
				j - start, coordstep[0], coordstep[1]));
		//mlx_put_pixel(cub->lines, i, j, 0x997070FF);
		j++;
	}
	while (j < WINHEIGHT)
		mlx_put_pixel(cub->lines, i, j++, 0);
}

void	lineupdate(t_cub *cub)
{
	unsigned int	i;
	void			*tex;

	i = 0;
	ft_raycasting(cub);
	while (i < WINWIDTH)
	{
		if (cub->sight[i].worient == -1)
			tex = cub->stex;
		else if (cub->sight[i].worient == 0)
			tex = cub->etex;
		else if (cub->sight[i].worient == 2)
			tex = cub->wtex;
		else
			tex = cub->ntex;
		scanline(cub, tex, i++);
	}
}
