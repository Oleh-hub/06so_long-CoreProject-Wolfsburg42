/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:20:16 by oruban            #+#    #+#             */
/*   Updated: 2023/11/29 19:53:36 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstiter
// Prototype void ft_lstiter(t_list *lst, void (*f)(void *));
// Turn in files -
// Parameters lst: The address of a pointer to a node.
// f: The address of the function used to iterate on the list.
// Return value None
// External functs. None
// Description Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node.

#include "libft.h"

// #include <unistd.h>
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }				t_list;

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f || !lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
