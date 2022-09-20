/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:56:41 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/20 11:13:30 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ms_exit(t_parsing *cts, char *cmndline)
{
	int	exval;

	if (cts->cmndtable[1])
		exval = ft_atoi(cts->cmndtable[1]);
	else
		;// Get $? value.
	free(cmndline);
	free_tables(cts);
	return (exval);
}
