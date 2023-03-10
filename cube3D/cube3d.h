/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:58:53 by senari            #+#    #+#             */
/*   Updated: 2023/03/10 10:52:14 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <math.h>

// CONSTANTS

# define RES_WIDTH 320

/**
 * Resolution width
 * Raycasting in Wolfenstein3D throw a ray for each pixel in width so it affect a lot in perfomance
*/

# define RES_HEIGHT 240

/**
 * Resolution height
 * Height is fake?? I know so far our game is really 2D for calculations, so it sholud affect perfomance but not much
*/

# define CELL_LENGTH 64

/**
 * Cell length
 * Amount of coordinates of the side of a cell of the map
 * We´ll be moving inside of cells, no more teleport like so_long :D
*/

# define VISION_FIELD M_PI/3

/**
 * Vision Field
 * Total angle of player vision, typically between 60 and 90 grades in games
 * its better to work with radians, 360 grades is 2π radianes
 * so 60 is π/3 radians, M_PI is a constant defined in math.h for π
 * if we want 90 grades it would be π/2, there is a constant defined in math.h for that: M_PI_2
*/


//     STRUCTURES                                                             //
typedef struct s_mapdata
{
	char	**cmap;
	char	*npath;
	char	*wpath;
	char	*spath;
	char	*epath;
	int		floorc;
	int		ceilic;
}			t_mapdata;

typedef struct s_cub
{
	t_mapdata	mdata;
}			t_cub;

typedef struct s_player
{
	float	coord_x;
	float	coord_y;
	float	sight_direction;
} t_player;

typedef struct s_vision_point
{
	float	length;
	int		wall_orientation;
}t_vision_point;

typedef struct s_raycasting
{
	t_vision_point	sight[RES_WIDTH];
} t_raycasting;

typedef struct s_collision
{
	int wall_collision;// yes/not
	int x;//point of collision
	int y;// point of colision
} t_collision

typedef struct s_ray
{
	float angle;
	int direct_v;// arriba/abajo
	int direct_h;// izquierda/derecha
	t_collision vertical;
	t_collision horizontal;

} t_ray;

//     PARSING                                                                //

/**
* @brief Returns 0 for valid filenames or -1 for invalid ones.
*
* @param s: The name of the file.
* @param len: The length of the filename string.
*
* @return 
*/
int		filecheck(const char *s, size_t len);

/**
* @brief A function that takes a string beginning by a digit character and
* returns the number it represent in the range [0, 255] or -1 if the value falls
* out of range. The character length of the number in the given string is passed
* onto the integer pointed to by the offset parameter ONLY if the given number
* falls in the range.
*
	* @param s: The string beginning by the first digit of the number to convert
	* to int.
	* @param offset: Pointer to an integer to store the length of the number,
	* or NULL.
	*
	* @return 
*/
int		atouc(const char *s, int *offset);

/**
* @brief Opens and parses mapfile, storing the processed values in cub and
* exiting after printing the corresponding error if something goes wrong.
*
* @param mapfile: The path to the file containing the map information.
* @param cub: A pointer to the data structure where everything will be stored.
*/
void	parsemap(char *mapfile, t_cub *cub);

/**
* @brief Stores the path to the walls' textures inside cub. Error exits if
* something goes wrong.
*
* @param fd: File descriptor of the map file.
* @param cub: Pointer to the data structure.
*/
void	gettextures(int fd, t_cub *cub);

//     UTILS                                                                  //

/**
* @brief Print "Error\n" followed by msg to stderr.
*
	* @param msg
	*/
void	errmsg(char *msg);

#endif
