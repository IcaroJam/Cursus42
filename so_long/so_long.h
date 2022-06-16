/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:26:18 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/16 11:52:43 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx/mlx.h"

typedef struct s_program
{
	void	*mlxptr;
	void	*winptr;
}	t_program;

typedef struct s_image
{
	void	*imgptr;
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;
}	t_image;

void	ft_mlx_pixel_put(t_image *img, int x, int y, int color);

#endif
