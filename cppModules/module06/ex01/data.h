/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:19:51 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/15 11:25:07 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
#define DATA_H

#include <stdint.h>

typedef struct	data {
	int		num;
	char	*str;
}				Data;

uintptr_t	serialize(Data *ptr);
Data		*deserialize(uintptr_t raw);

#endif
