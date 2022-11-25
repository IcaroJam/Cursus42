/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:24:33 by senari            #+#    #+#             */
/*   Updated: 2022/11/25 19:30:41 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
	public:
		std::string	ideas[100];

		Brain();
		Brain(const Brain &cpyFrom);
		Brain &operator=(const Brain &cpyFrom);
		~Brain();
};

#endif
