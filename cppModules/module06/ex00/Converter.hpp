/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:05:16 by senari            #+#    #+#             */
/*   Updated: 2022/12/31 16:54:26 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <cstdlib>
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
