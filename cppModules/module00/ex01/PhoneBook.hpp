/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:04:57 by senari            #+#    #+#             */
/*   Updated: 2022/09/04 16:37:11 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

class PhoneBook {
	public:
		void	contact_add();
		void	book_reorg();
		void	contact_display() const;

		PhoneBook();
		~PhoneBook();

	private:
		Contact _contactArray[8];
		int		_lastContact;
};

#endif
