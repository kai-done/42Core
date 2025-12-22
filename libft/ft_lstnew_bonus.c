/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:00:20 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/26 18:00:25 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*uh;

	uh = (t_list *)malloc(sizeof(t_list));
	if (uh == NULL)
		return (NULL);
	uh -> content = content;
	uh -> next = NULL;
	return (uh);
}

/*
 the content (= content) is from void *content
 the content (-> content) is from the struct
 the (= content) is what we want to store in (-> content)
 next is null because it's the last node in the list
 */
