/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:22:57 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/19 12:47:12 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ms_pwd(void)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	if (!tmp)
	{
		errno = ENOENT;
		return (1);
	}
	ft_putstr_fd(tmp, 1);
	free(tmp);
	return (0);
}
