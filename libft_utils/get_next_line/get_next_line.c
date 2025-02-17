/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:09:53 by mourhouc          #+#    #+#             */
/*   Updated: 2025/02/17 09:26:18 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_buffer(char *save_buffer, int fd)
{
	char	*buffer;
	char	*temp;
	ssize_t	len;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(save_buffer), NULL);
	len = 1;
	while (len > 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
			return (free(buffer), free(save_buffer), NULL);
		buffer[len] = '\0';
		temp = ft_strjoin(save_buffer, buffer);
		if (!temp)
			return (free(buffer), free(save_buffer), NULL);
		free(save_buffer);
		save_buffer = temp;
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (save_buffer);
}

static char	*set_line(char *save_buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (save_buffer[i] != '\0' && save_buffer[i] != '\n')
		i++;
	if (save_buffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (save_buffer[i] != '\0' && save_buffer[i] != '\n')
	{
		line[i] = save_buffer[i];
		i++;
	}
	if (save_buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*clean_line(char *save_buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save_buffer[i] != '\0' && save_buffer[i] != '\n')
		i++;
	if (!save_buffer[i])
	{
		free(save_buffer);
		return (NULL);
	}
	new_buffer = malloc(ft_strlen_gnl(save_buffer) - i);
	if (!new_buffer)
		return (free(save_buffer), NULL);
	i++;
	while (save_buffer[i])
		new_buffer[j++] = save_buffer[i++];
	new_buffer[j] = '\0';
	free(save_buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*save_buffer;
	char		*buffer;

	if (fd > OPEN_MAX || BUFFER_SIZE <= 0 || fd < 0 || read(fd, NULL, 0) < 0)
		return (free(save_buffer), save_buffer = NULL);
	save_buffer = fill_buffer(save_buffer, fd);
	if (!save_buffer || *save_buffer == 0)
		return (free(save_buffer), save_buffer = NULL);
	buffer = set_line(save_buffer);
	if (!buffer)
		return (free(save_buffer), save_buffer = NULL);
	save_buffer = clean_line(save_buffer);
	return (buffer);
}
