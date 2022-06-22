/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:26:18 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/22 16:39:21 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include "mlx/mlx.h"

typedef struct s_image
{
	void	*imptr;
	char	*addr;
	int		bpp;
	int		linsz;
	int		end;
}	t_image;

typedef struct s_anim
{
	void	*frame0;
	void	*frame1;
	char	*addr;
	int		bpp;
	int		linsz;
	int		end;
}	t_anim;

typedef struct s_tile
{
	char	type;
	int		update;
	int		interacted;
}	t_tile;

typedef struct s_map
{
	char	*str;
	t_tile	**tile;
	int		rows;
	int		clms;
	int		len;
	int		collec;
	int		egress;
	int		plpos;
}	t_map;

typedef struct s_player
{
	int		xpos;
	int		ypos;
	int		collectedcoins;
	void	*cursprt;
}	t_player;

typedef struct s_program
{
	void		*mlxptr;
	void		*winptr;
	t_player	player;
	t_map		map;
	t_image		wllsprt;
	t_image		bgsprt;
	t_anim		coinsprt;
	t_anim		exitsprt;
	t_anim		playsprt;
	int			frame;
	int			xspsz;
	int			yspsz;
}	t_program;

void	ft_pxlp(t_image *img, int x, int y, int color);
void	printerror(t_program *mlx, char *msg);
void	maperror(t_program *mlx, char *msg);
void	premap(char *file, t_program *mlx);
void	mapprocess(t_program *mlx);
void	interactivity(t_program *mlx, int i, int x, int y);
void	textureinit(t_program *mlx);
void	rendermap(t_program *mlx);
void	vanish_tiles(t_map *map);
void	textureerror(t_program *mlx, char *msg);
void	imagedel(t_program *mlx);
int		closer(void *program);
int		keystroked(int key, void *program);
int		animate(void *program);

#endif
