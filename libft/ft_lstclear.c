/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:35:57 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/05/05 16:03:38 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*temp;

	if (!lst || !*lst || !del)
		return ;
	temp = (*lst)->next;
	while (temp)
	{
		ft_lstdelone(*lst, del);
		*lst = temp;
		temp = (*lst)->next;
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
