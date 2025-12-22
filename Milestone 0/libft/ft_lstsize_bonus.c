/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:01:07 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/26 18:01:08 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	num;

	num = 0;
	while (lst != NULL)
	{
		num++;
		lst = lst -> next;
	}
	return (num);
}

/*
 this is to check how many structures there are
 like checking how many steps in a ladder
*/
