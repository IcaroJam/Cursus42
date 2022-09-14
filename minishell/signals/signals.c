/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:26:27 by phijano-          #+#    #+#             */
/*   Updated: 2022/09/13 17:57:42 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//averiguar porque saca el anoying ^C !!

void  INT_handler()//ctrl + C funcion
{
/*	unsigned char c;
	c = 9;
	write(1, &c, 1);
	write(1, &c, 1);
	c = 8;
	write(1, &c, 1);
	write(1, &c, 1);
	write(1, &c, 1);
	write(1, &c, 1);
	write(1, &c, 1);
	c = 127;
	write(1, &c, 1);
	write(1, &c, 1);*/
	ft_putstr_fd("\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void  QUIT_handler()//ctrl + \ funcion, ni idea de que hacer por ahora
{

	ft_putstr_fd("Ctrl+\\ pulsado\n", 1);
	//rl_on_new_line();
	//rl_redisplay();
	//readline("minishell: ");
	//exit(0);
}
