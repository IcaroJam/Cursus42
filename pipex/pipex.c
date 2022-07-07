/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:57:40 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/07 11:34:39 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**pathmaker(char **envp)
{
	char	**ret;
	char	*temp;

	while (ft_strncmp("PATH", *envp, 4))
	{
		if (!*envp)
			return (NULL);
		envp++;
	}
	temp = ft_substr(*envp, 5, ft_strlen(*envp));
	if (!temp)
		return (NULL);
	ret = ft_split(temp, ':');
	ft_free((void **) &temp);
	return (ret);
}

static void	inerrors(int argc, char **argv, char **envp, t_piper *piper)
{
	if (argc != 5)
	{
		write(2, "No. of args error.", 18);
		exit(1);
	}
	piper->infd = open(argv[1], O_RDONLY);
	if (piper->infd < 0)
	{
		write(2, "Couldn't open infile.", 21);
		exit(1);
	}
	piper->outfd = open(argv[4], O_TRUNC | O_CREAT | O_RDWR | 0000644);
	if (piper->outfd < 0)
	{
		write(2, "Couldn't open outfile.", 22);
		exit(1);
	}
	piper->paths = pathmaker(envp);
	if (!piper->paths)
	{
		write(2, "Unable to create path array.", 28);
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	//Comprobación de los parámetros de entrada. Gestión de error inicial.
	//Llamada a pipex, donde se harán los forks con una función que se encargue
	//de la separación entre procesos y llame a la función correspondiente.
	//Comprobación de errores del fork.
	t_piper	piper;

	inerrors(argc, argv, envp, &piper);
	return (0);
}
