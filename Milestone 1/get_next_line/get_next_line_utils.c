/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_net_line_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:33:10 by kkwek             #+#    #+#             */
/*   Updated: 2025/12/11 16:33:12 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	num;

	num = 0;
	while (c[num] != '\0')
		num++;
	return (num);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*paste;
	const unsigned char	*copy;
	size_t				num;

	paste = dest;
	copy = src;
	num = 0;
	while (num < n)
	{
		paste[num] = copy[num];
		num++;
	}
	return (dest);
}

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


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;
	size_t	num;
	size_t	str1;

	num = 0;
	str1= ft_strlen(s1);
	len = str1 + ft_strlen(s2);
	s3 = (char *)malloc(len + 1);
	if (s3 == NULL)
		return (NULL);
	while (s1[num] != '\0')
	{
		s3[num] = s1[num];
		num++;
	}
	num = 0;
	while (s2[num] != '\0')
	{
		s3[num + str1] = s2[num];
		num++;
	}
	s3[len] = '\0';
	return (s3);
}

char	*join_and_free(char *s1, char *s2)
{
	char	*result;
	
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}
