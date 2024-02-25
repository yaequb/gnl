/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesques <nefdesq@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:09:16 by ndesques          #+#    #+#             */
/*   Updated: 2024/02/24 16:09:16 by ndesques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *this_str, char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!this_str)
	{
		this_str = (char *)malloc(1 * sizeof(char));
		this_str[0] = '\0';
	}
	if (!this_str || !buffer)
		return (NULL);
	str = malloc((ft_strlen(this_str) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (this_str)
		while (this_str[++i])
			str[i] = this_str[i];
	while (buffer[j])
		str[i++] = buffer[j++];
	str[ft_strlen(this_str) + ft_strlen(buffer)] = '\0';
	free(this_str);
	return (str);
}

char	*ft_get_line(char *this_str)
{
	char	*str;
	int		i;

	i = 0;
	if (!this_str[i])
		return (NULL);
	while (this_str[i] && this_str[i] != '\n')
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (this_str[i] && this_str[i] != '\n')
	{
		str[i] = this_str[i];
		i++;
	}
	if (this_str[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_next_line(char *this_str)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (this_str[i] && this_str[i] != '\n')
		i++;
	if (!this_str[i])
	{
		free(this_str);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(this_str) - i) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	while (this_str[i])
		str[j++] = this_str[i++];
	str[j] = '\0';
	free(this_str);
	return (str);
}
