/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:24:05 by oruban            #+#    #+#             */
/*   Updated: 2023/12/11 14:50:35 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstadd_back
// Prototype void ft_lstadd_back(t_list **lst, t_list *new);
// Turn in files -
// Parameters lst: The address of a pointer to the first link of
// a list.
// new: The address of a pointer to the node to be
// added to the list.
// Return value None
// External functs. None
// Description Adds the node ’new’ at the end of the list.

#include "libft.h"
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }				t_list;

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}
// The last line: "ft_lstlast(*lst)->next = new;"
// substituets the following code, where "t_list *tmp;" is needed 
// lose the reference to the original head of the list:
	// t_list *tmp;
	// tmp = *lst;
	// while (tmp->next)
	// {
	// 	tmp = tmp->next;
	// }
	// (tmp)->next = new;
