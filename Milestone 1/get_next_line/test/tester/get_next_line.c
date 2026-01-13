#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*buffer;
	int		i;
	int		byte_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	line = malloc(BUFFER_SIZE + 1);
	if (line == NULL)
		return (free(buffer), NULL);

	line[0] = '\0';
	while (byte_read > 0)
	{
		buffer[byte_read] = '\0';
		if (remainder)
		{
			line = join_and_free(line, remainder);
			free(remainder);
			remainder = NULL;
		}
		line = join_and_free(line, buffer);
		if (line == NULL)
			return (NULL);
		i = 0;
		while (line[i] != '\0' && line[i] != '\n')
			i++;
		if (line[i] == '\n')
		{
			//return ("BBBBB");
			if (line[i+1] != '\0')
				remainder = stridup(&line[i+1]);
			line[i+1] = '\0';
			return(free(buffer), line);
		}
		if (line == NULL)
			return (NULL);
		byte_read = read(fd, buffer, BUFFER_SIZE);
	}

	if (line
		//&& line[0] != '\n'
	 	&& line [0] != '\0')
		return (free(buffer), line);

	return (free(line), free(buffer), NULL);
}
