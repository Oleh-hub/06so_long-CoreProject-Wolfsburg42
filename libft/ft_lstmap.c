/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:54:53 by oruban            #+#    #+#             */
/*   Updated: 2023/12/01 21:56:03 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name
// 	ft_lstmap
// Prototype 
// 	t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// Turn in files -
// Parameters 
// 	lst: The address of a pointer to a node.
// 	f: The address of the function used to iterate on the list.
// 	del: The address of the function used to delete the content of a node 
// 		if needed.
// Return 
// 	value The new list.
// 	NULL if the allocation fails.
// External functs.
// 	malloc, free
// Description 
// 	Iterates the list ’lst’ and applies the function ’f’ on the content 
// 	of each node. Creates a new list resulting of the successive 
// 	applications of the function ’f’. The ’del’ function is used to
// 	delete the content of a node if needed.

#include "libft.h"

// #include <unistd.h> // free()
// #include <stdlib.h>	// malloc()
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }				t_list;

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (!del || !f || !lst)
		return (NULL);
	new_lst = NULL;
	new_node = NULL;
	new_content = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
