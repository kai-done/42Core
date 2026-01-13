#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

#define BUFFER_SIZE 1024


int		strilen(const char *s1)
{
	int	i;
	i = 0;
	
	while (s1[i] != '\0')
		i++;
	return (i);
}

char	*strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		len;

	i = 0;
	len = strilen(s1);
	s2 = malloc(len + 1);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*strjoin(char *s1, char *s2)
{
	char	*s3;
	int	i;
	int	j;
	int	len1;
	int len2;

	i = 0;
	j = 0;
//	if (s1[0] == '\0' || s2[0] == '\0')
//		return ("");
	
	len1 = strilen(s1);
	len2 = strilen(s2);
	s3 = malloc(len1 + len2 + 1);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i+j] = s2[j];
		j++;
	}
	s3[i+j] = '\0';
	return (s3);
}

char	*join_and_free(char *s1, char *s2)
{
	char	*s3;

	s3 = strjoin(s1, s2);
	free(s1);
	return (s3);
}

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
			printf("Remainder found!\n");
			line = join_and_free(line, remainder);
			free(remainder);
			remainder = NULL;
		}
		line = join_and_free(line, buffer);
		i = 0;
		while (line[i] != '\0' && line[i] != '\n')
			i++;
		if (line[i] == '\n')
		{
			//return ("BBBBB");
			if (line[i+1] != '\0')
				remainder = strdup(&line[i+1]);
			line[i+1] = '\0';
			return(free(buffer), line);
		}
		byte_read = read(fd, buffer, BUFFER_SIZE);
	}

	if (line 
		//&& line[0] != '\n'
	 	&& line [0] != '\0')
		return (free(buffer), line);

	return (free(line), free(buffer), NULL);
}

int main(void) {
    int fd = 0;  // Using standard input (keyboard)
    char *line;

	line = get_next_line(fd);
	printf("%s\n", line);
    while (line != NULL) {
        printf("Got line: %s\n", line);
        free(line);  // Don't forget to free the memory after usage        
		line = get_next_line(fd);
    }

    return 0;
}

