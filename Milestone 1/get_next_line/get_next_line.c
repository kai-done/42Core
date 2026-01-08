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

char *get_next_line(int fd)
{

	static char *left;
	char		*line;
	char		*tmp;
	char		buffer[BUFFER_SIZE + 1];
	int			i;
	int			inner;
	
	if(BUFFER_SIZE <= 0 || fd == -1)
		return (NULL);
	line = malloc(BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	inner = read(fd, buffer, BUFFER_SIZE);
	
	line[0] = '\0';
	while (inner > 0)
	{
		buffer[inner] = '\0';
		if (left)
		{
			line = join_and_free(line, left);
			free(left);
			left = NULL;
		}
		tmp = join_and_free(line, buffer);
		line = ft_strdup(tmp);
		free(tmp);
		i = 0;
		while(line[i] != '\0' && line[i] != '\n')
			i++;
		if (line[i] == '\n')
		{
			if (line[i + 1] != '\0')
				left = ft_strdup(&line[i + 1]);
			else
				left = NULL;
			line[i + 1] = '\0';
			return (line);
		}
		inner = read(fd, buffer, BUFFER_SIZE);
	}	
	
	if (inner == 0 && line && line[0] != '\0')
		return (line);
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

int main()
{
	 char *line;

    // Read lines from stdin until EOF (Ctrl+D on Unix/Linux, Ctrl+Z on Windows)
    while ((line = get_next_line(0)) != NULL)  // 0 is the file descriptor for stdin
    {
        printf("%s", line);  // Print the line
        free(line);  // Free the memory for the line after printing
    }

    return 0;
}

int	main(void)
{
	char	*line;

	printf("Enter input (try pressing ENTER once):\n");

	line = get_next_line(0);
	if (line == NULL)
	{
		printf("get_next_line returned NULL\n");
		return (0);
	}

	printf("Returned line: \"%s\"\n", line);
	printf("First char ASCII: %d\n", line[0]);
	printf("Second char ASCII: %d (should be 0 if only \\n)\n", line[1]);

	free(line);

	line = get_next_line(0);
	if (line == NULL)
		printf("Second call returned NULL (EOF reached)\n");
	else
	{
		printf("Second call returned: \"%s\"\n", line);
		free(line);
	}

	return (0);
}
*/
