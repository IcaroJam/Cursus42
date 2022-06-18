/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:45:52 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/18 17:27:28 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** void	ft_pxlp(t_image *img, int x, int y, int color)
  * {
  *     char	*dst;
  *
  *     dst = img->addr + (y * img->linsz + x * (img->bpp / 8));
  *     *(unsigned int *) dst = color;
  *		// ESTO ES PA QUE DE ERROR DE NORMA LOL. AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
  * } */

void static	rendertile(t_program *mlx, int x, int y, char *spritedir)
{
	mlx->map.tile[y][x].imptr = mlx_xpm_file_to_image(mlx->mlxptr, spritedir,
			&mlx->xspsz, &mlx->yspsz);
	mlx_put_image_to_window(mlx->mlxptr, mlx->winptr, mlx->map.tile[y][x].imptr,
		80 * x, 80 * y);
}

void	rendermap(t_program *mlx)
{
	int	y;
	int	x;

	y = 0;
	mlx->xspsz = 80;
	mlx->yspsz = 80;
	while (y < mlx->map.rows)
	{
		x = 0;
		while (x < mlx->map.clms)
		{
			if (mlx->map.tile[y][x].type == '1')
				rendertile(mlx, x, y, "./sprites/Wall.xpm");
			else if (mlx->map.tile[y][x].type == 'P')
				rendertile(mlx, x, y, "./sprites/Player.xpm");
			else if (mlx->map.tile[y][x].type == 'C')
				rendertile(mlx, x, y, "./sprites/Collect.xpm");
			else if (mlx->map.tile[y][x].type == 'B')
				rendertile(mlx, x, y, "");
			else if (mlx->map.tile[y][x].type == 'E')
				rendertile(mlx, x, y, "./sprites/Egress.xpm");
			x++;
		}
		y++;
	}
}
