/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:57:40 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/13 16:56:19 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**pathmaker(char **envp)
{
	char	**ret;
	char	*temp;

	if (!envp || !*envp)
		return (NULL);
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
	if (argc < 5)
		errxit("No. of args error.\n");
	piper->hereflag = 0;
	if (!ft_strncmp("here_doc", argv[1], 8))
		piper->hereflag = 1;
	if (piper->hereflag)
	{
		piper->infd = open("here_doc.tmp", O_CREAT | O_WRONLY | O_APPEND, 0644);
		piper->outfd = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
		piper->herelim = argv[2];
	}
	else
	{
		piper->infd = open(argv[1], O_RDONLY);
		piper->outfd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	if (piper->infd < 0)
	{
		ft_putstr_fd("pipex: input: No such file or directory\n", 2);
		piper->inflag = 1;
	}
	if (piper->outfd < 0)
		errxit("Couldn't open outfile.\n");
	piper->paths = pathmaker(envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_piper	piper;

	unlink("here_doc.tmp");
	inerrors(argc, argv, envp, &piper);
	if (pipe(piper.fd) < 0)
		errxit("Failed to create a pipe.\n");
	pipex(&piper, argc, argv, envp);
	return (0);
}
