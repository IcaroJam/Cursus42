/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:08:09 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/21 14:51:19 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

// Rotation matrixes! Yay!
// The rotated vectors can easily be calculated by doing:
// (cosA -sinA)(X)
// (sinA  cosA)(Y)
// Where A is the angle a vector (X, Y) rotates.
// 0.0872... equals ~5º
static void	rotate(t_player *p, int dir)
{
	const float	a = 0.08726646259971647884618453842443;
	const float	olddirx = p->dirx;
	const float	oldcamx = p->camvectx;

	p->dirx = olddirx * cosf(dir * a) - p->diry * sinf(dir * a);
	p->diry = olddirx * sinf(dir * a) + p->diry * cosf(dir * a);
	p->camvectx = oldcamx * cosf(dir * a) - p->camvecty * sinf(dir * a);
	p->camvecty = oldcamx * sinf(dir * a) + p->camvecty * cosf(dir * a);
}

static void	move(t_player *p, int dir)
{
	float		newx;
	float		newy;
	const float	mvspeed = 0.1;
	//char	newtile;

	newx = p->x + dir * p->dirx * mvspeed;
	newy = p->y + dir * p->diry * mvspeed;
	//newtile = cub->mdata.cmap[(int)newy][(int)newx];
	/** if (isvalid(newtile) && newtile != '1')
	  * { */
		p->x = newx;
		p->y = newy;
	printf("X: %f, Y: %f\n", p->x, p->y);
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
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		rotate(&cub->player,-1);
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		rotate(&cub->player, 1);
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		move(&cub->player, 1);
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		move(&cub->player, -1);
}

void	mainhook(void *param)
{
	lineupdate(param);
}
