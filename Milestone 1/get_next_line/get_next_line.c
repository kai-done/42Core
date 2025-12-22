/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_net_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:31:27 by kkwek             #+#    #+#             */
/*   Updated: 2025/12/11 16:31:36 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	text[BUFFER_SIZE];
	char	*line;
	int		num;
	int		amt;
	int		a;

	num = 0;
	a = 0;
	if (fd == -1)
		return (NULL);
	amt = read(fd, text, BUFFER_SIZE);
	line = malloc(BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	while (amt > 0)
	{
		if (text[a] == '\n')
		{
			line[num] = '\0';
			return (line);
		}
		else
		{
			line[num] = text[a];
			num++;
		}
		a++;
	}
	if (amt == -1)
	{
		free(line);
		return (NULL);
	}
	if (num > 0)
	{
		line[num] = '\0';
		return (line);
	}
	
	free(line);
	return (NULL);
}
/*
int ft_strlen(char *s){

	int i = 0;
	while (*(s + i))
		i++;
	return i;
}

int	main()
{
	char *line;
//	line = get_next_line(0);
//	write(1, line, ft_strlen(line));
	//printf("--->%s", line);
	
//	line = get_next_line(0);
//	write(1, line, ft_strlen(line));
	//printf("--->%s", line);
	
	line = get_next_line(0);
	while (line)
	{
		write(1, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	free(line);
	

}
*/
