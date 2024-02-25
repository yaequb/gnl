/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesques <nefdesq@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:16:11 by ndesques          #+#    #+#             */
/*   Updated: 2024/02/24 17:16:11 by ndesques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *this_str);

int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *this_str, char *buffer);
char	*ft_get_line(char *this_str);
char	*ft_next_line(char *this_str);

#endif