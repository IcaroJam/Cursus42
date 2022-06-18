/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:26:18 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/18 16:20:22 by ntamayo-         ###   ########.fr       */
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

typedef struct s_image
{
	void	*imptr;
	char	*addr;
	char	type;
	int		bpp;
	int		linsz;
	int		end;
}	t_image;

typedef struct s_map
{
	char	*str;
	t_image	**tile;
	int		rows;
	int		clms;
	int		len;
	int		collec;
	int		egress;
	int		plpos;
}	t_map;

typedef struct s_program
{
	void	*mlxptr;
	void	*winptr;
	t_map	map;
	int		xspsz;
	int		yspsz;
}	t_program;

void	ft_pxlp(t_image *img, int x, int y, int color);
void	printerror(char *msg);
void	premap(char *file, t_map *map);
void	mapprocess(t_map *map);
void	rendermap(t_program *mlx);

#endif
