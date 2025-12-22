/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:09:40 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 19:09:42 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) + 1;
	copy = malloc(len);
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, s, len);
	return (copy);
}

/*
char	*ft_strdup(const char *s)
{
	if (s == NULL)
		return (NULL); // null terminate if input string is NULL
	size_t	len; // calculate length of s
	len = ft_strlen(s) + 1; // length of s + null terminator
	char	*copy; // store copied variable
	copy = malloc(len);
	if (copy == NULL)
		return (NULL); // malloc fail check
	ft_memcpy(copy, s, len); // copying s over
	return (copy);
}
*/
