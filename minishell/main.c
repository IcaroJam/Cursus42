/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:19:12 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/13 13:23:48 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

char	*g_env;

int	main(void)
{
	char		*cmndline;
	t_parsing	*cts;

	while (1) {
		cmndline = readline("pinche_perro@minishell~ $ ");
		// Handle signals here.
		if (cmndline[0])
		{
			add_history(cmndline);
			if (!ft_strncmp(cmndline, "EXIT", 5))
				break ;
			cts = parse_line(cmndline);
			// What if cts == NULL?
		}
		// Before executing command, check wether it is builtin or not.
		free(cmndline);
	}
	//
	system("leaks minishell");
	//
	return (0);
}
