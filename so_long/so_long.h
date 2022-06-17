/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:26:18 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/17 12:00:10 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include "mlx/mlx.h"

# define WINHEIGHT 1080
# define WINWIDTH 1920

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

typedef struct s_map
{
	char	*str;
	int		rows;
	int		clms;
	int		len;
}	t_map;

void	ft_pxlp(t_image *img, int x, int y, int color);
void	printerror(char *msg);
void	premap(char *file, t_map *map);
void	mapprocess(t_map *map);

#endif
