/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:16:08 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/24 14:16:11 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	num;
	char			*str;

	if (s == NULL)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	num = 0;
	while (s[num] != '\0')
	{
		str[num] = f(num, s[num]);
		num++;
	}
	str[num] = '\0';
	return (str);
}
