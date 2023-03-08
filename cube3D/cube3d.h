/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:58:53 by senari            #+#    #+#             */
/*   Updated: 2023/03/08 15:32:18 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>

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
int		gettextures(char *line, t_cub *cub);

/**
* @brief Stores the floor's and ceiling's colours inside cub. Exits on error.
*
* @param fd: File descriptor of the map file.
* @param cub: Pointer to the data structure.
*/
void	getcolours(int colstored[2], char *line, t_cub *cub);

//     UTILS                                                                  //

/**
* @brief Print "Error\n" followed by msg to stderr.
*
	* @param msg
	*/
void	errmsg(char *msg);

/**
* @brief Call errmsg and exit(1).
*
	* @param msg
	*/
void	errexit(char *msg);

/**
* @brief Free resources and call errexit.
*
	* @param msg
	* @param cub
	*/
void	frerrxit(char *msg, t_cub *cub);

#endif
