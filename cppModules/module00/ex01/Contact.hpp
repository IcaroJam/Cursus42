/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:50:14 by senari            #+#    #+#             */
/*   Updated: 2022/10/03 15:49:36 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact {
	public:
		bool		field_stuff();
		std::string	get_field(int i) const;

		Contact();
		~Contact();

	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phoneNum;
		std::string	_darkestSecret;
};

std::string	process_line(std::string &ret);

#endif
