/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:52:59 by oruban            #+#    #+#             */
/*   Updated: 2023/11/29 18:12:32 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstlast
// Prototype t_list *ft_lstlast(t_list *lst);
// Turn in files -
// Parameters lst: The beginning of the list.
// Return value Last node of the list
// External functs. None
// Description Returns the last node of the list.

#include "libft.h"
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }				t_list;

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
