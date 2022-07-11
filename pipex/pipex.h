/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:28:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/11 11:30:11 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct s_piper
{
	char	**paths;
	char	**currcmd;
	char	*cmdpath;
	int		bustdin;
	int		bustdout;
	int		infd;
	int		outfd;
	int		inflag;
	int		fd[2];
	int		childid[2];
}	t_piper;

void	errxit(char const *msg);
void	pipex(t_piper *piper, char **argv, char **envp);
char	*commander(t_piper *piper, char **argv, int childpos);
char	**pipesplit(char const *s, char c);

#endif
