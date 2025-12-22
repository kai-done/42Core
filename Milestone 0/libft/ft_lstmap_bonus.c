/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:03:15 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/26 18:03:16 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;
	void	*newcontent;

	newlist = NULL;
	while (lst != NULL)
	{
		newcontent = f(lst -> content);
		newnode = ft_lstnew(newcontent);
		if (!newnode)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst -> next;
	}
	return (newlist);
}

/*
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) {

    t_list *new_list = NULL;  // Step 1: Start with no nodes in the new list.
    t_list *new_node;

    while (lst != NULL) {
    
    	// Apply the function to the content of the current node.
        void *new_content = f(lst->content); 
         
        // Step 2: Create a new node with the transformed content.
        new_node = ft_lstnew(new_content);    
        
		// If memory allocation fails
        if (!new_node) {      
                        
        	// Clean up by freeing the new list.
            ft_lstclear(&new_list, del);      
            return NULL;
        }

		// Step 3: Add the new node to the new list.
        ft_lstadd_back(&new_list, new_node);  
        
        // Step 4: Move to the next node in the original list.
        lst = lst->next;                      
    }

    return new_list;  // Step 5: Return the new list.
}

*/
