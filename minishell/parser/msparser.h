/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msparser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:09:55 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/06 17:13:54 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSPARSER_H
# define MSPARSER_H

// Utilities for the lexing stage:
int	count_isspace(const char *line);
int	process_word(const char *line);
int	handle_quotes(const char *line, const char flag);

#endif
