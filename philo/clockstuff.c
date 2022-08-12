/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clockstuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:14:47 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/12 12:32:48 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	mstime(void)
{
	struct timeval	time;
	int				ret;

	gettimeofday(&time, NULL);
	ret = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ret);
}

int	timesince(t_prg *prg)
{
	return (mstime() - prg->starttime);
}
