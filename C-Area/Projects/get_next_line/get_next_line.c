/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:52:36 by soel-had          #+#    #+#             */
/*   Updated: 2025/11/28 12:24:20 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line(char *line, char *buffer)
{
	char	*tmp;

	if (!buffer)
		return (line);
	if (!line)
		return (ft_strdup(buffer));
	tmp = ft_strjoin(line, buffer);
	if (!tmp)
		return (NULL);
	free(line);
	return (tmp);
}

int	check_empty_line(char **line)
{
	if (!*line || (*line)[0] == '\0')
	{
		free(*line);
		*line = NULL;
		return (1);
	}
	return (0);
}

char	*extract_line(char **line)
{
	char	*result;
	char	*rest;
	size_t	i;

	if (check_empty_line(line))
		return (NULL);
	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	result = malloc(i + ((*line)[i] == '\n') + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, *line, i + ((*line)[i] == '\n'));
	result[i + ((*line)[i] == '\n')] = '\0';
	if ((*line)[i] == '\0')
	{
		free(*line);
		*line = NULL;
		return (result);
	}
	rest = ft_strdup(*line + i + 1);
	free(*line);
	*line = rest;
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	ssize_t		size;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!new_line_found(line))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
			return (free(buffer), free(line), line = NULL, NULL);
		if (size == 0)
			break ;
		buffer[size] = '\0';
		line = fill_line(line, buffer);
		if (!line)
			return (free(buffer), NULL);
	}
	free(buffer);
	result = extract_line(&line);
	return (result);
}
