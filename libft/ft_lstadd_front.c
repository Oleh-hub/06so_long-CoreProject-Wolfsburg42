/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:54:49 by oruban            #+#    #+#             */
/*   Updated: 2023/11/29 17:20:12 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstadd_front
// Prototype void ft_lstadd_front(t_list **lst, t_list *new);
// Turn in files -
// Parameters lst: The address of a pointer to the first link of
// a list.
// new: The address of a pointer to the node to be
// added to the list.
// Return value None
// External functs. None
// Description Adds the node ’new’ at the beginning of the list.

#include "libft.h"

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }				t_list;

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

// void t()
// {
// 	t_list* lst = ft_lstnew(NULL);		
// 	ft_lstadd_front(&lst, NULL);
// 	lst->next == lst
// }