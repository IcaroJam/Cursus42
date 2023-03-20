/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:08:09 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/20 13:19:33 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

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
