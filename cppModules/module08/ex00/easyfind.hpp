/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:17:28 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/01/17 12:38:23 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T> typename T::iterator	easyfind(T &cont, int findthis) {
	typename T::iterator	ret = std::find(cont.begin(), cont.end(), findthis);
	return (ret); // If the return value equals cont.end() the value wasn't found.
}

#endif
