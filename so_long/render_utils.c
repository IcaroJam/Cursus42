/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:45:52 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/16 12:10:05 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pxlp(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_size + x * (img->bpp / 8));
	*(unsigned int *) dst = color;
}
