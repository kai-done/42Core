/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:45:44 by kkwek             #+#    #+#             */
/*   Updated: 2025/11/21 20:45:46 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	num;
	int	words;

	num = 0;
	words = 0;
	while (s[num] != '\0')
	{
		while (s[num] == c)
			num++;
		if (s[num] != '\0')
			words++;
		while (s[num] != '\0' && s[num] != c)
			num++;
	}
	return (words);
}

static char	*word_dup(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **result, int i)
{
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
}

static int	word_end(const char *s, int i, char c)
{
	while ((s[i] != '\0') && (s[i] != c))
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		start;
	int		end;
	int		i;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	result = (char **)malloc(sizeof(*result) * (words + 1));
	if (result == NULL)
		return (NULL);
	end = 0;
	i = -1;
	while (++i < words)
	{
		while (s[end] == c)
			end++;
		start = end;
		end = word_end(s, end, c);
		result[i] = word_dup(s, start, end);
		if (result[i] == NULL)
			return (free_all(result, i), NULL);
	}
	return ((result[i] = NULL), result);
}

/*
static int	count_words(const char *s, char c)
{
	int	count = 0;

	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	free_all(char **arr, int i)
{
	while (i > 0)
	{
		free(arr[i - 1]);
		i--;
	}
	free(arr);
}

#include <stdlib.h>

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i = 0;
	int		start;
	int		end;

	if (!s)
		return (NULL);

	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);

	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			start = 0;
			while (s[start] && s[start] != c)
				start++;

			arr[i] = malloc(start + 1);
			if (!arr[i])
				return (free_all(arr, i), NULL);

			end = 0;
			while (end < start)
			{
				arr[i][end] = s[end];
				end++;
			}
			arr[i][end] = '\0';
			i++;
			s += start;
		}
	}
	arr[i] = NULL;
	return (arr);
}
*/
