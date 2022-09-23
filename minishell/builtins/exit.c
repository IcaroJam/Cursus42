/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:56:41 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/23 14:39:51 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern char	**g_env;

//
static void	leakcheck(void)
{
	system("leaks minishell");
}
//

int	ms_exit(t_parsing *cts, char *cmndline, char *prompt)
{
	int	exval;

	if (cts->cmndtable[1])
		exval = ft_atoi(cts->cmndtable[1]);
	else
		exval = ft_atoi(ms_getenv("?"));
	free(prompt);
	free(cmndline);
	free_cmndline(g_env);
	free_tables(cts);
	//
	leakcheck();
	//
	return (exval);
}
