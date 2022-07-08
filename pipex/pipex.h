/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:28:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/08 11:07:03 by ntamayo-         ###   ########.fr       */
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
	int		infd;
	int		outfd;
	int		fd[2];
	int		childid[2];
}	t_piper;

void	errxit(char const *msg);
void	pipex(t_piper *piper, char **argv, int argc);

#endif
