/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:08:09 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/20 19:04:05 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	rotate(t_cub *cub, int dir)
{
	float	pitwo;

	pitwo = 2 * M_PI;
	cub->player.a -= dir * 0.08726646259971647884618453842443;
	if (cub->player.a >= pitwo)
		cub->player.a -= pitwo;
	else if (cub->player.a < 0)
		cub->player.a += pitwo;
}

static void	move(t_cub *cub, int dir)
{
	float	newx;
	float	newy;
	//char	newtile;

	newx = cub->player.x + dir * cosf(cub->player.a);
	newy = cub->player.y + dir * sinf(cub->player.a);
	//newtile = cub->mdata.cmap[(int)newy][(int)newx];
	/** if (isvalid(newtile) && newtile != '1')
	  * { */
		cub->player.x = newx;
		cub->player.y = newy;
	printf("X: %f, Y: %f\n", cub->player.x, cub->player.y);
	/** } */
}

void	keyhooks(mlx_key_data_t keydata, void *param)
{
	t_cub	*cub;

	cub = param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(cub->mlx);
		return ;
	}
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		rotate(param, -1);
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		rotate(param, 1);
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		move(param, -1);
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		move(param, 1);
}

void	mainhook(void *param)
{
	lineupdate(param);
}
