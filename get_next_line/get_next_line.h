/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:47:59 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/10 16:32:21 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_buffprocess(int fd, char **buff, size_t *bufflen);
char	*ft_fragfetch(int *nlflag, char **buff);
char	*ft_fragconglomerator(int fd, char **buff);
char	*get_next_line(int fd);
void	*ft_bcalloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_linelen(const char *buff, int *nlflag);
char	*ft_strjoin(char *s1, char *s2);

#endif
