/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philosophers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:57:28 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/15 11:26:02 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PHILOSOPHERS_H
# define BONUS_PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <pthread.h>
# include <string.h>

typedef struct s_philosopher
{
	void		*ticketback;
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
}	t_prg;

// Input values
int		inputhandler(int argc, char **argv, t_prg *prg);

// Time functions
int		mstime(void);
int		timesince(t_prg *prg);
void	phisleep(t_prg *prg, int i);

// Libft functions
int		ft_ioverflw(char *str);
int		ft_strlen(const char *s);
int		ft_atoi(const char *str);

#endif
