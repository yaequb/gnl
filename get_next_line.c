/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesques <nefdesq@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:07:54 by ndesques          #+#    #+#             */
/*   Updated: 2024/02/24 16:07:54 by ndesques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

char	*ft_read_str(int fd, char *this_str)
{
	char	*buffer;
	int		bts;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bts = 1;
	while (!ft_strchr(this_str, '\n') && bts != 0)
	{
		bts = read(fd, buffer, BUFFER_SIZE);
		if (bts == -1)
		{
			free(this_str);
			return (NULL);
		}
		buffer[bts] = '\0';
		this_str = ft_strjoin(this_str, buffer);
	}
	free(buffer);
	this_str = ft_strjoin(this_str, buffer);
	return (this_str);
}

char	*get_next_line(int fd)
{
	static char	*this_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	this_str = ft_read_str(fd, this_str);
	if (!this_str)
		return (NULL);
	line = ft_get_line(this_str);
	this_str = ft_next_line(this_str);
	return (line);
}

#include <fcntl.h>
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("test/test1.txt", O_RDONLY);
	fd2 = open("test/test2.txt", O_RDONLY);
	fd3 = open("test/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
