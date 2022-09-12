/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:19:12 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/12 16:48:04 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char		*cmndline;
	t_parsing	*cts;

	while (1) {
		cmndline = readline("pinche_perro@minishell~ $ ");
		// Handle signals here.
		add_history(cmndline);
		if (!ft_strncmp(cmndline, "EXIT", 5))
			break ;
		cts = parse_line(cmndline);
		if (!cts)
		{
			free(cmndline);
			break ;
		}
		free(cmndline);
	}
	//
	system("leaks minishell");
	//
	return (0);
}
