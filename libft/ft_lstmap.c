/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:49:52 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/05/05 16:05:02 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*ret;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	ret = ft_lstnew(f(lst->content));
	if (!ret)
		return (NULL);
	temp = ret;
	while (lst->next)
	{
		temp->next = ft_lstnew(f(lst->next->content));
		if (!temp->next)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (ret);
}
