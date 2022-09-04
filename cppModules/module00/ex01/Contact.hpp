/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:50:14 by senari            #+#    #+#             */
/*   Updated: 2022/09/04 11:50:09 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	public:

		Contact();
		~Contact();

	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phoneNum;
		std::string	darkestSecret;
};

#endif
