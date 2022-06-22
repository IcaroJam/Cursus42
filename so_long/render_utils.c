/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:45:52 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/22 16:47:03 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

/** void	ft_pxlp(t_image *img, int x, int y, int color)
  * {
  *     char	*dst;
  *
  *     dst = img->addr + (y * img->linsz + x * (img->bpp / 8));
  *     *(unsigned int *) dst = color;
  *		// ESTO ES PA QUE DE ERROR DE NORMA LOL. AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
  * } */

void static	spritecompass(t_program *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlxptr, mlx->winptr, mlx->bgsprt.imptr,
		80 * x, 80 * y);
	if (mlx->map.tile[y][x].type == '1')
		mlx_put_image_to_window(mlx->mlxptr, mlx->winptr, mlx->wllsprt.imptr,
			80 * x, 80 * y);
	else if (mlx->map.tile[y][x].type == 'P')
		mlx_put_image_to_window(mlx->mlxptr, mlx->winptr, mlx->player.cursprt,
			80 * x, 80 * y);
	else if (mlx->map.tile[y][x].type == 'C' && !mlx->map.tile[y][x].interacted)
		mlx_put_image_to_window(mlx->mlxptr, mlx->winptr, mlx->coinsprt.frame0,
			80 * x, 80 * y);
	else if (mlx->map.tile[y][x].type == 'C' && mlx->map.tile[y][x].interacted)
		mlx_put_image_to_window(mlx->mlxptr, mlx->winptr, mlx->coinsprt.frame1,
			80 * x, 80 * y);
	else if (mlx->map.tile[y][x].type == 'B')
		mlx_put_image_to_window(mlx->mlxptr, mlx->winptr, mlx->playsprt.frame0,
			80 * x, 80 * y);
	else if (mlx->map.tile[y][x].type == 'E' && !mlx->map.tile[y][x].interacted)
		mlx_put_image_to_window(mlx->mlxptr, mlx->winptr, mlx->exitsprt.frame0,
			80 * x, 80 * y);
	else if (mlx->map.tile[y][x].type == 'E' && mlx->map.tile[y][x].interacted)
		mlx_put_image_to_window(mlx->mlxptr, mlx->winptr, mlx->exitsprt.frame1,
			80 * x, 80 * y);
	mlx->map.tile[y][x].update = 0;
}

void	rendermap(t_program *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < mlx->map.rows)
	{
		x = 0;
		while (x < mlx->map.clms)
		{
			if (mlx->map.tile[y][x].update)
				spritecompass(mlx, x, y);
			x++;
		}
		y++;
	}
}
