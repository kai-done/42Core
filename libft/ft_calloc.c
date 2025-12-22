/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:09:26 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 19:09:29 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	size_t	total;
	void	*alr;

	if (size != 0 && nmeb > SIZE_MAX / size)
		return (NULL);
	total = nmeb * size;
	alr = malloc(total);
	if (alr == NULL)
		return (NULL);
	ft_memset(alr, 0, total);
	return (alr);
}

/*
void	*ft_calloc(size_t nmeb, size_t size)
{
	if (size != 0 && nmeb > SIZE_MAX / size) //check for overflow
		return (NULL); // ensure it doesn't exceed the max limit
	size_t	total;
	total = nmeb * size; //total memory size
	void	*alr;
	alr = malloc(total); //allocates memory for 0s
	if (alr == NULL) // check if malloc fails
		return (NULL);
	ft_memset(alr, 0, total); // set it all to 0
	return (alr);
}
*/
