/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:45:31 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 20:45:34 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

/*
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*sta;
	char	*end;
	char	ca;
	size_t	num;
	size_t	len;

	ca = (char *) set;
	len = ft_strlen(s1);

	num = 0;
	while(s1[num] != '\0')
	{
		if (s1[num] != ca)
		{
			sta = &s1[num];
			break;
		}
		num++;
		len--;
	}
	num = ft_strlen(s1);
	while(s1[num] != ca)
	{
		end = s1[num];
		num--;
		len--;
	}
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	num = 0;
	while (str[num] != s1[end])
	{
		str[num] = s1[sta + num];
		num++;
	}
	str[num] = '\0';
	return (str);
}
*/

static int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	num;
	size_t	sta;
	size_t	end;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	sta = 0;
	while (s1[sta] && is_in_set(s1[sta], set))
		sta++;
	end = ft_strlen(s1);
	while (end > sta && is_in_set(s1[end - 1], set))
		end--;
	len = end - sta;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	num = 0;
	while (num < len)
	{
		str[num] = s1[sta + num];
		num++;
	}
	return ((str[num] = '\0'), str);
}
