/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:47:12 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/24 11:55:46 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int static	check_extension(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	len--;
	if (argv[len--] == 'r')
		if (argv[len--] == 'e')
			if (argv[len--] == 'b')
				if (argv[len] == '.')
					return (0);
	return (1);
}

void static	inputhandler(t_program *mlx, int argc, char *argv)
{
	if (argc != 2)
		printerror(mlx, "Wrong number of arguments.");
	if (check_extension(argv))
		printerror(mlx, "Wrong map file extension.");
}

void static	secureinit(t_program *mlx)
{
	mlx->mlxptr = NULL;
	mlx->winptr = NULL;
	mlx->frame = 0;
	mlx->foecount = 0;
	mlx->player.collectedcoins = 0;
	mlx->player.moves = 0;
	mlx->player.isdead = 0;
	mlx->player.won = 0;
}

int	main(int argc, char **argv)
{
	t_program	mlx;

	secureinit(&mlx);
	inputhandler(&mlx, argc, argv[1]);
	premap(argv[1], &mlx);
	mlx.mlxptr = mlx_init();
	if (!mlx.mlxptr)
		return (1);
	mlx.winptr = mlx_new_window(mlx.mlxptr, mlx.map.clms * 80,
			mlx.map.rows * 80, "Dune II");
	textureinit(&mlx);
	mlx_hook(mlx.winptr, 17, 0, closer, &mlx);
	mlx_hook(mlx.winptr, 2, 0, keystroked, &mlx);
	mlx_loop_hook(mlx.mlxptr, animate, &mlx);
	mlx_loop(mlx.mlxptr);
	return (0);
}
