/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:08:09 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/23 15:26:38 by ntamayo-         ###   ########.fr       */
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

static void	move(t_cub *cub, float xdir, float ydir)
{
	float		newx;
	float		newy;
	const float	mvspeed = 0.1;

	newx = cub->player.x + xdir * mvspeed;
	newy = cub->player.y + ydir * mvspeed;
	if (cub->mdata.cmap[(int)cub->player.y][(int)newx] != '1')
		cub->player.x = newx;
	if (cub->mdata.cmap[(int)newy][(int)cub->player.x] != '1')
		cub->player.y = newy;
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
}

static void	mouserotate(t_player *p)
{
	float		a;
	const float	olddirx = p->dirx;
	const float	oldcamx = p->camvectx;

	if (p->cursx)
	{
		a = atanf(p->cursx * 0.005);
		p->dirx = olddirx * cosf(a) - p->diry * sinf(a);
		p->diry = olddirx * sinf(a) + p->diry * cosf(a);
		p->camvectx = oldcamx * cosf(a) - p->camvecty * sinf(a);
		p->camvecty = oldcamx * sinf(a) + p->camvecty * cosf(a);
	}
}

void	mainhook(void *param)
{
	t_cub	*cub;

	cub = param;
	printf("%d\n", cub->player.cursx);
	mlx_get_mouse_pos(cub->mlx, &cub->player.cursx, &cub->player.cursy);
	mouserotate(&cub->player);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		rotate(&cub->player, -1);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		rotate(&cub->player, 1);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
		move(cub, cub->player.dirx, cub->player.diry);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
		move(cub, -cub->player.dirx, -cub->player.diry);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		move(cub, -cub->player.camvectx, -cub->player.camvecty);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		move(cub, cub->player.camvectx, cub->player.camvecty);
	mlx_set_mouse_pos(cub->mlx, 0, 0);
	lineupdate(param);
	updateminimap(cub);
}
