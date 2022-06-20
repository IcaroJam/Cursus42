/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:47:12 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/20 17:51:54 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
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

void static	inputhandler(int argc, char *argv)
{
	if (argc != 2)
		printerror("Wrong number of arguments.");
	if (check_extension(argv))
		printerror("Wrong map file extension.");
}

int	main(int argc, char **argv)
{
	t_program	mlx;

	inputhandler(argc, argv[1]);
	premap(argv[1], &mlx.map);
	mlx.mlxptr = mlx_init();
	if (!mlx.mlxptr)
		return (1);
	mlx.winptr = mlx_new_window(mlx.mlxptr, mlx.map.clms * 80,
			mlx.map.rows * 80, "ThisIsATest B)");
	textureinit(&mlx);
	mlx_hook(mlx.winptr, 17, 0, closer, &mlx);
	mlx_loop(mlx.mlxptr);
	return (0);
}
