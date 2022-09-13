/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:19:12 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/13 18:54:31 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

char	*g_env;

static void	print_row(char **row)
{
	for (int i = 0; row[i]; i++) {
		printf("%s ", row[i]);
	}
}

static void	print_table(t_parsing *cts)
{
	for (int i = 0; !cts[i].islast; i++) {
		printf("Cmnds: ");
		print_row(cts[i].cmndtable);
		printf("\nIns: ");
		print_row(cts[i].ins);
		printf("\nOuts: ");
		print_row(cts[i].outs);
		printf("\n");
	}
}

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
			if (cts)
				print_table(cts);
			// What if cts == NULL?
			// Free cts when finished with it AND when exiting.
		}
		// Before executing command, check wether it is builtin or not.
		free(cmndline);
	}
	//
	system("leaks minishell");
	//
	return (0);
}
