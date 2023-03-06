/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:07:06 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/06 17:29:46 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	main(void)
{
	void	*mlx = mlx_init(1080, 720, "Boi oh boi", false);
	/** void	*img = mlx_new_image(mlx, 1080, 720);
	  * mlx_image_to_window(mlx, img, 0, 0);
	  * mlx_put_pixel(img, 10, 10, 0xFF0000FF); */
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
