/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:19:12 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/16 14:00:12 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*g_env;

static void	print_row(char **row)
{
	for (int i = 0; row[i]; i++) {
		printf("\"%s\" ", row[i]);
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

int	main(int argc, char **argv, char **envp)
{
	char		*cmndline;
	t_parsing	*cts;

	(void)argc;//arreglar
	(void)argv;//arreglar
	cts = NULL;
	while (1)
	{
		cmndline = readline("pinche_perro@minishell~ $ ");
		// Handle signals here.
		//if (!cmndline)
		//	ft_ctrl_D();
		signal(SIGINT, INT_handler);
		//signal(SIGQUIT, QUIT_handler); para hacer funcion Ctrl + \ ?
		signal(SIGQUIT, SIG_IGN);//para ignorarlo
		//signal(SIGQUIT, SIG_DFL);//el manejador por defecto, para que mate el proceso. hara falta para los child?
		if (cmndline[0])
		{
			add_history(cmndline);
			if (!ft_strncmp(cmndline, "exit", 5))
				break ;
			cts = parse_line(cmndline);
			if (cts)
				print_table(cts);
			// What if cts == NULL?
			// Free cts when finished with it AND when exiting.
		}
		// Before executing command, check wether it is builtin or not.
		ft_executor(cts, envp);
		free(cmndline);
	}
	//
	system("leaks minishell");
	//
	return (0);
}
