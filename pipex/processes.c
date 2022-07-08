/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:56:39 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/08 11:36:38 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void static	firstchild(void)
{
	//En caso de que no se pueda ejecutar el coso:
	if (execve(const char *file, char *const *argv, char *const *envp) < 0)
		errxit("Couldn't execute/find the command.");
}

void static	lastchild(void)
{

}

void static	parent(t_piper *piper)
{
}

void	pipex(t_piper *piper, char **argv, int argc)
{
	piper->childid[0] = fork();
	if (piper->childid[0] < 0)
		errxit("Failed to child up :(");
	if (!piper->childid[0])
		firstchild();
	else
	{
		piper->childid[1] = fork();
		if (piper->childid[1] < 0)
			errxit("Failed to have a second kid D:");
		if (!piper->childid[1])
			lastchild();
		else
			parent(piper);
	}
}
