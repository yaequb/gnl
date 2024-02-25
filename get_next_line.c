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
// #include <stdio.h>
// #include <fcntl.h>

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
			free(buffer);
			return (NULL);
		}
		buffer[bts] = '\0';
		this_str = ft_strjoin(this_str, buffer);
	}
	free(buffer);
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

// int	main(void)
// {
// 	int		i;
// 	int		fd;
// 	char	*line;

// 	fd = open("./test1.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 6)
// 	{
// 		line = get_next_line(fd);
// 		printf("line %d: (%s)\n", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
