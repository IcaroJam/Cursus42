/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:05:16 by senari            #+#    #+#             */
/*   Updated: 2022/12/21 18:40:46 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>

class Converter {
	public:
		Converter();
		Converter(const char *givenString);
		Converter(const Converter &cpyFrom);
		Converter &operator=(const Converter &cpyFrom);
		~Converter();

		void	plausibilityCheck(void);

	private:
		std::string	_inStr;
		bool		_plausible[4];

		char		_cval;
		int			_ival;
		float		_fval;
		double		_dval;
};

#endif
