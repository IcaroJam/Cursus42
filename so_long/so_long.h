/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:26:18 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/23 13:31:04 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
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
	int		foes;
	int		plpos;
}	t_map;

typedef struct s_foe
{
	int		xpos;
	int		ypos;
	int		direction;
	void	*cursprt;
}	t_foe;

typedef struct s_player
{
	int		xpos;
	int		ypos;
	int		collectedcoins;
	int		moves;
	int		isdead;
	int		won;
	void	*cursprt;
}	t_player;

typedef struct s_program
{
	void		*mlxptr;
	void		*winptr;
	t_player	player;
	t_foe		*foelst;
	t_map		map;
	t_image		wllsprt;
	t_image		bgsprt;
	t_image		black;
	t_image		winscreen;
	t_image		deathscreen;
	t_anim		coinsprt;
	t_anim		exitsprt;
	t_anim		playsprt;
	t_anim		foesprt;
	int			frame;
	int			xspsz;
	int			yspsz;
	int			xscsz;
	int			yscsz;
}	t_program;

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
