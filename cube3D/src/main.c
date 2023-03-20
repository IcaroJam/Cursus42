/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:07:06 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/20 13:07:29 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void	handleinputandinit(int argc, char **argv, t_cub *cub)
{
	if (argc == 1)
		errexit("Missing map. Usage: [./cube3D <<mapname>>.cub]");
	else if (argc > 2)
		errexit("Too many input arguments. Usage: [./cube3D <<mapname>>.cub]");
	if (filecheck(argv[1], ft_strlen(argv[1])) == -1)
		errexit("Invalid map format. Usage: [./cube3D <<mapname>>.cub]");
	cub->mdata.cmap = NULL;
	cub->mdata.npath = NULL;
	cub->mdata.wpath = NULL;
	cub->mdata.spath = NULL;
	cub->mdata.epath = NULL;
	cub->player.x = 0;
	cub->mlx = NULL;
}

static void	loadimgsandinit(t_cub *cub)
{
	cub->mlx = mlx_init(WINWIDTH, WINHEIGHT, "N&P's Cube3D!", false);
	if (!cub->mlx)
		frerrxit("MLX init failed!", cub);
	cub->ntex = mlx_load_png(cub->mdata.npath);
	cub->wtex = mlx_load_png(cub->mdata.wpath);
	cub->stex = mlx_load_png(cub->mdata.spath);
	cub->etex = mlx_load_png(cub->mdata.epath);
	if (!cub->ntex || !cub->wtex || !cub->stex || !cub->etex)
		frerrxit("Failed to load png textures.", cub);
	cub->nimg = mlx_texture_to_image(cub->mlx, cub->ntex);
	cub->wimg = mlx_texture_to_image(cub->mlx, cub->wtex);
	cub->simg = mlx_texture_to_image(cub->mlx, cub->stex);
	cub->eimg = mlx_texture_to_image(cub->mlx, cub->etex);
	if (!cub->nimg || !cub->wimg || !cub->simg || !cub->eimg)
		frerrxit("Failed to load images from textures.", cub);
}

void	leakcheck(void)
{
	system("leaks cube3D");
}

void	infodump(t_cub *cub)
{
	unsigned int	i;

	i = 0;
	printf("Textures:\n\tNO: %s\n\tWE: %s\n\tSO: %s\n\tEA: %s\nColors:\n\tF: %x\n\tC: %x\nMap:\n", cub->mdata.npath, cub->mdata.wpath, cub->mdata.spath, cub->mdata.epath, cub->mdata.floorc, cub->mdata.ceilic);
	while (i < cub->mdata.ysize)
		printf("%s\n", cub->mdata.cmap[i++]);
	printf("Player:\n\tX: %f\n\tY: %f\n\tA: %f\n", cub->player.x, cub->player.y, cub->player.a);
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	atexit(leakcheck);
	handleinputandinit(argc, argv, &cub);
	parsemap(argv[1], &cub);
	infodump(&cub);
	loadimgsandinit(&cub);

	backpaint(&cub);
	mlx_image_to_window(cub.mlx, cub.nimg, 0, 0);
	mlx_put_pixel(cub.back, 100, 50, 0xff0000ff);

	mlx_key_hook(cub.mlx, keyhooks, &cub);
	mlx_loop(cub.mlx);
	freecub(&cub);
	return (0);
}
