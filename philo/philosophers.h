/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:57:28 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/12 12:43:02 by ntamayo-         ###   ########.fr       */
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
	void		*ticketback;
	pthread_t	philo;
	int			id;
	int			leftfork;
	int			rightfork;
	int			lstmealtime;
	int			timeseaten;
}	t_philosopher;

// Program struct. Index in the fork array of the fork right to a philosopher
// will always be the same as the philosopher ID and 0 for the fork
// right to the last philosopher.
typedef struct s_prg
{
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				notepme;
	int				starttime;
	int				philodeath;
	int				notepmeflag;
	t_philosopher	*phls;
	pthread_mutex_t	*forks;
	pthread_t		mstrthrd;
}	t_prg;

// Thread functions
void	*sofic_routine(void *thelot);
void	*everwatcher(void *wholething);

// Input values
int		inputhandler(int argc, char **argv, t_prg *prg);

// Time functions
int		mstime(void);
int		timesince(t_prg *prg);

// Libft functions
int		ft_ioverflw(char *str);
int		ft_strlen(const char *s);
int		ft_atoi(const char *str);

#endif
