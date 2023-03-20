/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:31:39 by phijano-          #+#    #+#             */
/*   Updated: 2023/03/20 22:06:38 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_is_wall(t_cub *game, t_collision collision, int direct_x, int direct_y)
{
	unsigned int	cell_x;
	unsigned int	cell_y;

//	cell_x = x/CELL_LENGTH - orientation_x;
//	cell_y = y/CELL_LENGTH - orientation_y;
//	printf("dx%d, dy%d\n", direct_x, direct_y);
	if (direct_x < 0)
		direct_x = 1;
	else
		direct_x = 0;
	if (direct_y < 0)
		direct_y = 1;
	else
		direct_y = 0;
	cell_x = collision.x / CELL_LENGTH - direct_x;
	cell_y = collision.y / CELL_LENGTH - direct_y;
	//horizontal collision: direct_x = 0
	//horizontal collision: direct_y 1 arriba, 0 abajo
	//vertical collision: direct_x 0 derecha, 1 izquierda 
	//vertical collision: direct_y = 0
//	printf("x %d y %d dx %d, dy %d\n", cell_x, cell_y, direct_x, direct_y);
//	write(2, "2111\n", 5);
	if (cell_x >= game->mdata.xsize || cell_y >= game->mdata.ysize || game->mdata.cmap[cell_y][cell_x] == '1') 
	{
//		write(2, "2112\n", 5);

		return (1);
	}
	return (0);
}

void	ft_get_direction(t_ray *ray)
{
	if (sinf(ray->angle) > 0)
		ray->direct_v = -1;
	else
		ray->direct_v = 1;
	if (cosf(ray->angle) > 0)
		ray->direct_h = 1;
	else
		ray->direct_h = -1;
	/** if (ray->angle >= 2 * M_PI)
	  *     ray->angle = ray->angle - (2 * M_PI);
	  * else if (ray->angle < 0)
	  *     ray->angle = ray->angle + (2 * M_PI); */
	// ver que pasa cuando la direccion coincide con los ejes (solo habrá colisiones de un tipo)
}

void	ft_get_collisions(t_cub *game, t_ray *ray)
{
	int	count;
	int	cell_x;
	int	cell_y;

	//write(1, "20\n", 3);
	cell_x = game->player.x / CELL_LENGTH;
	cell_y = game->player.y / CELL_LENGTH;
//	printf("cx %d, cy %d\n", cell_x, cell_y);
//	printf("px %f, py%f\n",game->player.x, game->player.y);
//	printf("ray angle %f\n", ray->angle);
	ray->vertical.wall_collision = 0;
	count = 0;
	if (ray->direct_h == 1)
		count++;
//	write(1, "210\n", 4);
	while (!ray->vertical.wall_collision && ray->direct_h != 0)
	{
		//	ray->vertical.x = (cell_x * CELL_LENGTH) + CELL_LENGTH * n //cuidado n empezaria en 1 si el rayo va a la derecha o en 0 si va a la izquierda
		ray->vertical.x = (cell_x * CELL_LENGTH) + CELL_LENGTH * (count * ray->direct_h);
		//ray->vertical.y = -tan(ray->angle) * (ray->vertical.x - game->player.x) - game->player.y;
		ray->vertical.y = -tan(ray->angle) * (ray->vertical.x - game->player.x) + game->player.y;

		
//		write(1, "211\n", 4);
		ray->vertical.wall_collision = ft_is_wall(game, ray->vertical, ray->direct_h , 0);// arreglar argumentos
																						  //
//		write(1, "212\n", 4);
		count++;
	}
   	ray->horizontal.wall_collision = 0;
	count = 0;
	if (ray->direct_v == 1)
		count++;
//	write(1, "220\n", 4);
	
	while (!ray->horizontal.wall_collision && ray->direct_v != 0)
	{
		//	ray->horizontal.y = (cell_y * CELL_LENGTH) + CELL_LENGTH * n //cuidado n empezaria en 1 si el rayo va hacia abajo o en 0 si hacia arriba
		ray->horizontal.y = (cell_y * CELL_LENGTH) + CELL_LENGTH * (count * ray->direct_v); //cuidado n empezaria en 1 si el rayo va hacia abajo o en 0 si hacia arriba
	//	ray->horizontal.x = -(ray->horizontal.y + game->player.y)/tan(ray->angle) + game->player.x;
		ray->horizontal.x = -(ray->horizontal.y - game->player.y)/tan(ray->angle) + game->player.x;

		ray->horizontal.wall_collision = ft_is_wall(game, ray->horizontal, 0, ray->direct_v);// arreglar argumentos
		count++;
	}
	
}

float ft_get_distance(t_cub *game, t_collision collision)
{
	return (sqrt(exp2(game->player.x - collision.x) + exp2(game->player.y - collision.y)));
}

void	ft_get_vision_point(t_cub *game, t_ray *ray, int index) //mirar si conviene calcular la distancia en el calculo de colisiones para no hacerlo dos veces en
																//el caso que haya collisiones con el muro en las dos direcciones para el mismo indice de colisiones
{
	if (ray->vertical.wall_collision && ray->horizontal.wall_collision)
	{
		if (ft_get_distance(game, ray->vertical) > ft_get_distance(game, ray->horizontal))
			ray->vertical.wall_collision = 0;
		else 
			ray->horizontal.wall_collision = 0;
	}
	if (ray->vertical.wall_collision)
	{
//		printf("collision E/O");
		game->sight[index].distance = ft_get_distance(game, ray->vertical);
		game->sight[index].wall_orientation = ray->direct_h + 1;// 0 Este 2 Oeste //comprobar las direcciones!!!!!!
		if (ray->direct_h > 0)
			game->sight[index].wall_texture_coord = (int)ray->horizontal.y % CELL_LENGTH;//fix
		else
			game->sight[index].wall_texture_coord = CELL_LENGTH - (int)ray->horizontal.y % CELL_LENGTH;//fix
	}
	else
	{
//		printf("collision N/S");
		game->sight[index].distance = ft_get_distance(game, ray->horizontal);
		game->sight[index].wall_orientation = ray->direct_v;// -1 Sur 1 Norte //comprobar las direcciones!!!!!!
		if (ray->direct_v > 0)
			game->sight[index].wall_texture_coord = CELL_LENGTH - (int)ray->horizontal.x % CELL_LENGTH;//fix
		else
			game->sight[index].wall_texture_coord = (int)ray->horizontal.x % CELL_LENGTH;//fix
	}
}

void	ft_raycasting(t_cub *game)
{
	int		count;
	t_ray	ray;

	count = -1;
//	write(1, "00\n", 3);

	while (++count < WINWIDTH)
//	while (++count < 1)
	{
		ray.angle = game->player.a + VISION_FIELD / 2 - VISION_FIELD * count / (WINWIDTH - 1);
		if (count == 0 || count == 399 || count == 799)
			printf("[%3d] Angle: %f, Distance: %f\n", count, ray.angle, game->sight[count].distance);
//		write(1, "10\n", 3);
		ft_get_direction(&ray);
		if (count == 0 || count == 399 || count == 799)
			printf("[%3d] Angle: %f, Distance: %f\n", count, ray.angle, game->sight[count].distance);

//		write(1, "20\n", 3);
		ft_get_collisions(game, &ray);
		if (count == 0 || count == 399 || count == 799)
			printf("[%3d] Angle: %f, Distance: %f\n", count, ray.angle, game->sight[count].distance);

//		write(1, "30\n", 3);
		ft_get_vision_point(game, &ray, count);
		if (count == 0 || count == 399 || count == 799)
			printf("[%3d] Angle: %f, Distance: %f\n", count, ray.angle, game->sight[count].distance);

//		write(1, "40\n", 3);
	}
//	write(1, "50\n", 3);
//	exit(0);
}

//teoría
/*
raycasting (t_cub *cub)
{
	// hace falta saber celda del jugador??
	
	cell_x = cub->player->coord_x/CELL_LENGTH;
	cell_y = cub->player->coord_y/CELL_LENGTH;

	// -collision_y - cub->player->coord_y = tan(ray) * (collision_x - cub->player->coord_x); nuestra formula de la recta
	collision_y = -tan(ray) * (collision_x - cub->player->coord_x) - cub->player->coord_y;
	collision_x = -(collision_y + cub->player->coord_y)/tan(ray) + cub->player->coord_x;

	//	ecuacion recta y - y1 = m(x -x1) pero nosotros tenemos el eje y invertido asi que la nuestra es:
	//	-y -y1 = m(x -x1) !!!!!!!
	//	m = tangente del angulo, angulo es el angulo del rayo
	//	y - coord_y = tan ray[n](x - coord_x)
	//	coord_x and coord_y player coords
	// colisiones verticales dependera de la direccion del rayo izquierda\derecha
	//	x = 0 , x = 64 ..... las x = a la unidad de la cellda por la celda en la que este
	// se averigua la y de la colision y si es de un muro
	// colisiones horizontales dependera de la direccion del rayo arriba\abajo
	//	y = 0 , y = 64 ..... las x = a la unidad de la celda por la celda en la que este
	// se averigua la x de la colision y si hay un muro
	// y
	// |      /
	// |    / 
	// |  / ) angulo 
	// |/____________x
	// tener en cuenta las coordenadas y ejes en nuestro mapa para ver si hay que ajustar algo del ángulo o lo que sea 


	ray[n] = (player->sight_direction + VISION_FIELD/2) - (VISION_FIELD/WIDTH * n);// cálculo del ángulo de cada rayo
	

	if (ray > 0)
		//va hacia arriba, en nuestro caso -y (orientacion muro sur)
	else
		//va hacia abajo, en nuestro caso +y (muro norte)
	if (ray < M_PI_2 || ray > -M_PI_2)//M_PI_2 es una constante de math.h igual a π/2
		//va hacia la derecha en nuestro caso +x (muro oeste)
	else
		//va hacia la izquierda, en nuestro caso -x (muro este)
	//De momento no se lo que pasa cuando el ángulo es igual a los ejes, tan(0) = 0, tan(π/2) = ∞! revisar
	
	vertical_collision_x = (cell_x * CELL_LENGTH) + CELL_LENGTH * n //cuidado n empezaria en 1 si el rayo va a la derecha o en 0 si va a la izquierda
	vertical_colision_y // utilizar fórmula para collision_y donde collision_x = vertical_collision_x

	horizontal_collision_y = (cell_y * CELL_LENGTH) + CELL_LENGTH * n //cuidado n empezaria en 1 si el rayo va hacia abajo o en 0 si hacia arriba
	horizontal_colision_x // utilizar fórmula para collision_x donde collision_Y = horizontal_collision_y

	// hacer bucle hasta encontrar la primera colision con el muro (ver si alternamos las dos colisiones (vertical, horizontal) 
	// hasta encontrar la primera o buscar las dos y comparar las distancias para devolver la menor
	
	// cálculo de la distancia de la colision al fin!!
	// a^2+b^2=c^2
	// distancia = √(x2−x1)2+(y2−y1)2
	
	collision_distance = sqrt(exp2(cub->player->coord_x - collision_x) + exp2(cub->player->coord_y - collision_y));
}
*/
