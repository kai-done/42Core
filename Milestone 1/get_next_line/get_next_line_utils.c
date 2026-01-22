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

int	length(char *s1)
{
	int	i;

	i = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i] != '\0')
		i++;
	return (i);
}

char	*duplicate(char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	s2 = malloc(length(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	loop(char *s1, char *s2, int i)
{
	int		j;

	j = 0;
	while (s1[j] != '\0')
	{
		s2[i] = s1[j];
		i++;
		j++;
	}
	return (i);
}

char	*join(char *s1, char *s2)
{
	char	*s3;
	int		i;

	i = 0;
	if (s1 == NULL)
		s1 = duplicate("");
	if (s1 == NULL || s2 == NULL)
		return (free(s1), NULL);
	s3 = malloc(length(s1) + length(s2) + 1);
	if (s3 == NULL)
		return (free(s1), NULL);
	i = loop(s1, s3, i);
	i = loop(s2, s3, i);
	s3[i] = '\0';
	return (free(s1), s3);
}
