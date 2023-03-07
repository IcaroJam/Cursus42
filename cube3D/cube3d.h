/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:58:53 by senari            #+#    #+#             */
/*   Updated: 2023/03/07 09:50:09 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>

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
int	atouc(const char *s, int *offset);

#endif
