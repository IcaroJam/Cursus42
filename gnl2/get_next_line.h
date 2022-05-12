/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:47:59 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/12 12:38:35 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
void	ft_strlcpy(char *dst, char *src, int size);
int		ft_linelen(char *mem);
int		ft_strlen(char *s);
int		lecture_master(int fd, char **time_machine);
char	*the_line_maker(char **time_machine);
char	*get_next_line(int fd);

#endif
