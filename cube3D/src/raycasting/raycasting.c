/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:31:39 by phijano-          #+#    #+#             */
/*   Updated: 2023/03/13 09:13:19 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_is_wall(t_cub *game, float x, float y, int orientation_x, int orientation_y)//fix
{
	int cell_x;
	int cell_y;
	
	cell_x = x/CELL_LENGTH - orientation_x;
	cell_y = y/CELL_LENGTH - orientation_y;

	//horizontal collision: orientation_x = 0
	//horizontal collision: orientation_y 1 arriba, 0 abajo
	//vertical collision: orientation_x 0 derecha, 1 izquierda 
	//vertical collision: orientation_y = 0
	
	if (game->mdata.cmap[cell_y, cell_x] == '1')
		return 1;
	return 0;
}

void	ft_get_direction(t_ray *ray)
{
	ray->direct_v = 0;
	ray->direct_h = 0;
	if (ray->angle >= 2 * M_PI)
		ray->angle = ray->angle - (2 * M_PI);
	else if (ray->angle < 0)
		ray->angle = ray->angle + (2 * M_PI);
	if (ray->angle > 0 && ray->angle < M_PI)
		ray->direct_v = -1// arriba
	else
		ray->direct_v = 1//abajo
	if ((ray->angle > 0 && ray->angle < M_PI_2) || (ray->angle > 3 * M_PI_2 && ray->angle < 2 * M_PI))
		ray->direct_h = 1//derecha
	else
		ray->direct_h = -1//izquierda
	// ver que pasa cuando la direccion coincide con los ejes (solo habrá colisiones de un tipo)
}

void	ft_get_collisions(t_cub *game, t_ray *ray)
{
	int	count;
	int	cell_x;
	int	cell_y;

	cell_x = game->player.coord_x/CELL_LENGTH;
	cell_y = game->player.coord_y/CELL_LENGTH;
	ray->vertical.wall_collision = 0;
	count = 0;
	if (ray->direct_h == 1)
		count++;
	while (!ray->vertical.wall_collision && ray->direct_h != 0)
	{
		//	ray->vertical.x = (cell_x * CELL_LENGTH) + CELL_LENGTH * n //cuidado n empezaria en 1 si el rayo va a la derecha o en 0 si va a la izquierda
		ray->vertical.x = (cell_x * CELL_LENGTH) + CELL_LENGTH * (count * ray->direct_h)
		ray->vertical.y = -tan(ray->angle) * (ray->vertical.x - game->player->coord_x) - game->player->coord_y;
		ray->vertical.wall_collision = ft_is_wall();// arreglar argumentos
		count++;
	}
   	ray->horizontal.wall_collision = 0;
	count = 0;
	if (ray->direct_v == 1)
		count++;
	while (!ray->horizontal.wall_collision && ray->direct_v != 0)
	{
		//	ray->horizontal.y = (cell_y * CELL_LENGTH) + CELL_LENGTH * n //cuidado n empezaria en 1 si el rayo va hacia abajo o en 0 si hacia arriba
		ray->horizontal.y = (cell_y * CELL_LENGTH) + CELL_LENGTH * (count * ray_direc_v) //cuidado n empezaria en 1 si el rayo va hacia abajo o en 0 si hacia arriba
		ray->horizontal.xx = -(ray->horizontal.y + game->player->coord_y)/tan(ray->angle) + game->player->coord_x;
		ray->horizontal.wall_collision = ft_is_wall();// arreglar argumentos
		count++;
	}
}

float ft_get_distance(t_cub *game, t_collision collision)
{
	return (sqrt(exp2(game->player->coord_x - collision.x) + exp2(game->player->coord_y - collision.y)));
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
		game->raycasting.sight[index].distance = ft_get_distance(game, ray->vertical);
		game->raycasting.sight[index].wall_orientation = ray->direct_v// -1 Sur 1 Norte
	}
	else
	{
		game->raycasting.sight[index].distance = ft_get_distance(game, ray->horizontal);
		game->raycasting.sight[index].wall_orientation = ray->direct_h + 1// 0 Este 2 Oeste
	}
}

void	ft_raycasting(t_cub *game)
{
	int		count;
	t_ray	ray;

	count = -1;
	while (++count < RES_WIDTH)
	{
		ray.angle = (game->player->sight_direction + VISION_FIELD/2) - (VISION_FIELD/WIDTH * count);
		ft_get_direction(&ray);
		ft_get_collisions(game, &ray)
		ft_get_vision_point(game, &ray, count);
	}
}


//teoría
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
