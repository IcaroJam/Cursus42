/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:57:40 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/11 11:30:02 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**pathmaker(char **envp)
{
	char	**ret;
	char	*temp;

	while (ft_strncmp("PATH=", *envp, 5))
	{
		if (!*envp)
			return (NULL);
		envp++;
	}
	temp = ft_substr(*envp, 5, ft_strlen(&envp[0][5]));
	if (!temp)
		return (NULL);
	ret = ft_split(temp, ':');
	ft_free((void **) &temp);
	return (ret);
}

static void	inerrors(int argc, char **argv, char **envp, t_piper *piper)
{
	if (argc != 5)
		errxit("No. of args error.\n");
	piper->infd = open(argv[1], O_RDONLY);
	if (piper->infd < 0)
	{
		ft_putstr_fd("pipex: input: No such file or directory\n", 2);
		piper->inflag = 1;
	}
	piper->outfd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (piper->outfd < 0)
		errxit("Couldn't open outfile.\n");
	piper->paths = pathmaker(envp);
	if (!piper->paths)
		errxit("Unable to create path array.\n");
}

int	main(int argc, char **argv, char **envp)
{
	t_piper	piper;

	piper.inflag = 0;
	inerrors(argc, argv, envp, &piper);
	if (pipe(piper.fd) < 0)
		errxit("Failed to create the pipe.\n");
	pipex(&piper, argv, envp);
	return (0);
}
