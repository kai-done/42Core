/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:45:14 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 20:45:16 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;
	size_t	num;

	num = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
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
		s3[num + ft_strlen(s1)] = s2[num];
		num++;
	}
	s3[len] = '\0';
	return (s3);
}
