/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:57:28 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/10 18:44:54 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef struct s_philosopher
{
	pthread_t	philo;
	int			id;
}	t_philosopher;

// Program struct. Index in the fork array of the fork right to a philosopher
// will always be the same as the philosopher ID.
typedef struct s_prg
{
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				notepme;
	t_philosopher	*phls;
	pthread_mutex_t	*forks;
}	t_prg;

// Input values
int	inputhandler(int argc, char **argv, t_prg *prg);

// Libft functions
int	ft_ioverflw(char *str);
int	ft_strlen(const char *s);
int	ft_atoi(const char *str);

#endif
