/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_net_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkwek <kkwek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:33:20 by kkwek             #+#    #+#             */
/*   Updated: 2025/12/11 16:33:22 by kkwek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <fcntl.h>
# include <stdint.h>
# include <stddef.h>

int		length(char *s1);
int		loop(char *s1, char *s2, int i);
int		before(char **remainder, char *buffer, int byte_read, int fd);
char	*duplicate(char *s1);
char	*join(char *s1, char *s2);
char	*get_next_line(int fd);
char	*during(int byte_read, char *line, char **remainder, char *buffer);

#endif 
