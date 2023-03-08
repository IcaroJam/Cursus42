/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:31:39 by phijano-          #+#    #+#             */
/*   Updated: 2023/03/08 13:56:01 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

raycasting (t_cub cub)
{
	// hace falta saber celda del jugador??
	
	cell_x = cub->player->coord_x/CELL_LENGTH;
	cell_y = cub->player->coord_y/CELL_LENGTH;

	//	ecuacion recta y - y1 = m(x -x1)
	//	m = tangente del angulo, angulo es el angulo del rayo
	//	y - coord_y = tan ray[n](x - coord_x)
	// colisiones verticales dependera de la direccion del rayo izquierda\derecha
	//	x = 0 , x = 64 ..... las x = a la unidad de la cleda por la celda en la que este
	// se averigua la y de la colision y si es de un muro
	// colisiones horizontales dependera de la direccion del rayo arriba\abajo
	//	y = 0 , y = 64 ..... las x = a la unidad de la cleda por la celda en la que este
	// se averigua la x de la colision y si es de un muro
	// y
	// |      /
	// |    / 
	// |  / ) angulo 
	// |/____________x
	// tener en cuenta las coordenadas y ejes en nuestro mapa para ver si hay que ajustar algo del ángulo o lo que sea 

	ray[n] = (player->sight_direction + VISION_FIELD/2) - (VISION_FIELD/WIDTH * n);

	// cálculo del ángulo de cada rayo
}
