/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:45:52 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/23 11:54:19 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "mlx/mlx.h"
#include "so_long.h"

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

void static	textupdate(t_program *mlx)
{
	char	*text;

	text = ft_itoa(mlx->player.moves);
	mlx_put_image_to_window(mlx->mlxptr, mlx->winptr, mlx->black.imptr,
		80 * (mlx->map.clms - 1), 80 * (mlx->map.rows - 1));
	mlx_string_put(mlx->mlxptr, mlx->winptr, 80 * (mlx->map.clms - 0.55),
		80 * (mlx->map.rows - 0.45), 0x00c0a682, text);
	free(text);
}

void static	renderscreen(t_program *mlx, void *ptr)
{
	mlx_put_image_to_window(mlx->mlxptr, mlx->winptr,
		ptr, ((mlx->map.clms * 80) - 400) / 2,
		((mlx->map.rows * 80) - 240) / 2);
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
	textupdate(mlx);
	if (mlx->player.won)
		renderscreen(mlx, mlx->winscreen.imptr);
	else if (mlx->player.isdead)
		renderscreen(mlx, mlx->deathscreen.imptr);
}
