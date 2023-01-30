/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:05:16 by senari            #+#    #+#             */
/*   Updated: 2023/01/30 12:18:50 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>

class Converter {
	public:
		Converter();
		Converter(const char *givenString);
		Converter(const Converter &cpyFrom);
		Converter &operator=(const Converter &cpyFrom);
		~Converter();

		void	convDisplay(void);

	private:
		std::string	_inStr;
		bool		_plausible[4];
		bool		_isFloatingExtreme;

		char		_cval;
		int			_ival;
		float		_fval;
		double		_dval;

		bool	weirdValsCheck(std::string str);
		void	typeCheck(void);
		void	typeConversion(void);
		void	typeCasting(void);
};

#endif
