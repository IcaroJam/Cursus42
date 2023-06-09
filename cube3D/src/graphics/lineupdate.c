/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineupdate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:27:42 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/06/09 16:34:35 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static unsigned int	texturer(mlx_texture_t *tex, int j, int texcrd, float stp)
{
	int	pixindex;

	pixindex = 4 * (tex->width * (int)(j * stp) + texcrd);
	return ((tex->pixels[pixindex] << 24) | (tex->pixels[pixindex + 1] << 16)
		| (tex->pixels[pixindex + 2] << 8) | (tex->pixels[pixindex + 3]));
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
	start = -h * 0.5 + cub->halfheight;
	end = h * 0.5 + cub->halfheight;
	if (end > WINHEIGHT)
		end = WINHEIGHT;
	coordstep[0] = tex->width * cub->sight[i].wtexc;
	coordstep[1] = tex->height / (float)h;
	j = start;
	if (j < 0)
		j = 0;
	while (j < end)
	{
		mlx_put_pixel(cub->lines, i, j, texturer(tex,
				j - start, coordstep[0], coordstep[1]));
		j++;
	}
}

// The lines image is deleted and recreated each time so it's pixels can be
// modified without the screen being repainted everytime. Huuuuge perf gains.
void	lineupdate(t_cub *cub)
{
	unsigned int	i;
	void			*tex;

	i = 0;
	if (cub->lines)
		mlx_delete_image(cub->mlx, cub->lines);
	cub->lines = mlx_new_image(cub->mlx, WINWIDTH, WINHEIGHT);
	if (!cub->lines)
		freecub(cub);
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
	mlx_image_to_window(cub->mlx, cub->lines, 0, 0);
	mlx_set_instance_depth(cub->lines->instances, 1);
}
