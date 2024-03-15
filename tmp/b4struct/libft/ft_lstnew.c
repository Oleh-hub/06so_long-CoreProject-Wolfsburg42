/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:26:21 by oruban            #+#    #+#             */
/*   Updated: 2023/11/29 17:02:14 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstnew
// Prototype t_list *ft_lstnew(void *content);
// Turn in files -
// Parameters #1. The content to create the new element with.
// Return value The new element.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a new
// element. The variable ’content’ is initialized
// with the value of the parameter ’content’. The
// variable ’next’ is initialized to NULL.

// Here is a description of the fields of the t_list struct:
// • content : The data contained in the element. The void * allows to store 
// any kind of data.
// • next : The next element’s address or NULL if it’s the last element.

#include "libft.h"

// typedef struct	s_list
// {
// 	void *content;
// 	struct s_list *next;
// }				t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// #include <stdio.h>

// int main()
// {
// 	t_list 	*head = NULL;
// 	int 	i[] = {1, 2, 3, 4, 5};
// 	t_list	*new_node;

// 	for (long unsigned int j = 0; j < sizeof(i) / sizeof(i[0]); j++)
// 	{
// 		new_node = ft_lstnew(&i[j]);
// 		if(!new_node)
// 		{
// 			printf("Memory allocationi failed.\n");
// 			return 1;
// 		}
// 		new_node->next = head;
// 		head = new_node;
// 	}
// 		// while(new_node->next)
// 		// {
// 		// 	printf("%p\n", new_node->next);
// 		// 	printf("%d\n", *(int *) new_node->content);
// 		// 	new_node = new_node->next;
// 		// }
// 		// 	printf("%p\n", new_node->next);
// 		// 	printf("%d\n", *(int *) new_node->content);
// 	while(head)
// 	{
// 		printf("%p\n", head->next);
// 		printf("%d\n", *(int *) head->content);
// 		head = head->next;
// 	}
// 	head = new_node;
// 	while(head)
// 	{
// 		new_node = head;
// 		head = new_node->next;
// 		free(new_node);
// 	}
// }
