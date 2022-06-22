/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheckII.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:58:14 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/22 11:41:33 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void static	stuffcount(t_map *map, char c)
{
	if (c == 'C')
		map->collec++;
	else if (c == 'E')
		map->egress++;
	else if (c == 'P')
		map->plpos++;
}

void static	top(t_program *mlx, int *i)
{
	while (mlx->map.str[*i] != '\n')
	{
		if (mlx->map.str[*i] != '1')
			maperror(mlx, "Map error: UPPER WALL BREACH!!!");
		(*i)++;
		mlx->map.clms++;
	}
}

void static	bottom(t_program *mlx, int	*iclms, int *i)
{
	while (mlx->map.str[*i] != '\n')
	{
		if (mlx->map.str[*i] != '1')
			maperror(mlx, "Map error: LOWER WALL BREACH!!!");
		(*i)++;
		(*iclms)++;
	}
}

void static	midrows(t_program *mlx, int	*irows, int *iclms, int *i)
{
	while (*irows < mlx->map.rows)
	{
		*iclms = 0;
		if (mlx->map.str[*i] != '1')
			maperror(mlx, "Map error: LEFT WALL BREACH!!!");
		while (mlx->map.str[*i] != '\n')
		{
			stuffcount(&mlx->map, mlx->map.str[*i]);
			(*i)++;
			(*iclms)++;
		}
		if (mlx->map.str[*i - 1] != '1')
			maperror(mlx, "Map error: RIGHT WALL BREACH!!!");
		if (*iclms != mlx->map.clms)
			maperror(mlx, "Map error: Wall shift???");
		(*i)++;
		(*irows)++;
	}
}

void	mapprocess(t_program *mlx)
{
	int	irows;
	int	iclms;
	int	i;

	i = 0;
	top(mlx, &i);
	i++;
	irows = 2;
	midrows(mlx, &irows, &iclms, &i);
	iclms = 0;
	bottom(mlx, &iclms, &i);
	if (iclms != mlx->map.clms)
		maperror(mlx, "Map error: Wall shift???");
	if (mlx->map.plpos == 0)
		maperror(mlx, "Map error: Player not found!");
	if (mlx->map.plpos > 1)
		maperror(mlx, "Map error: No doppelgangers allowed!");
	if (mlx->map.collec == 0)
		maperror(mlx, "Map error: It's a sad world without collectibles...");
	if (mlx->map.egress == 0)
		maperror(mlx, "Map error: There is no escape...");
}
