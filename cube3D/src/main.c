/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:07:06 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/07 10:44:26 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void	handleinput(int argc, char **argv)
{
	if (argc == 1)
	{
		errmsg("Missing map. Usage: [./cube3D <<mapname>>.cub]");
		exit(1);
	}
	else if (argc > 2)
	{
		errmsg("Too many input arguments. Usage: [./cube3D <<mapname>>.cub]");
		exit(1);
	}
	if (filecheck(argv[1], ft_strlen(argv[1])) == -1)
	{
		errmsg("Invalid map format. Usage: [./cube3D <<mapname>>.cub]");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	handleinput(argc, argv);
	return (0);
}
