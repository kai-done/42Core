#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"


int		strilen(const char *s1)
{
	int	i;
	i = 0;
	
	while (s1[i] != '\0')
		i++;
	return (i);
}

char	*stridup(const char *s1)
{
	char	*s2;
	int		i;
	int		len;

	i = 0;
	len = strilen(s1);
	s2 = malloc(len + 1);
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
	if (s3 == NULL)
		return (NULL);
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
	if (s3 == NULL)
		return (NULL);
	return (s3);
}

