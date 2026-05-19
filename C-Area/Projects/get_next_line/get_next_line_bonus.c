/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:50:23 by soel-had          #+#    #+#             */
/*   Updated: 2025/11/27 12:52:09 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fill_line(char *arr, char *buffer)
{
	char	*tmp;

	if (!buffer)
		return (arr);
	if (!arr)
		return (ft_strdup(buffer));
	tmp = ft_strjoin(arr, buffer);
	if (!tmp)
		return (NULL);
	free(arr);
	return (tmp);
}

int	check_empty_line(char **arr)
{
	if (!*arr || (*arr)[0] == '\0')
	{
		free(*arr);
		*arr = NULL;
		return (1);
	}
	return (0);
}

char	*extract_line(char **arr)
{
	char	*result;
	char	*rest;
	size_t	i;

	if (check_empty_line(arr))
		return (NULL);
	i = 0;
	while ((*arr)[i] && (*arr)[i] != '\n')
		i++;
	result = malloc(i + ((*arr)[i] == '\n') + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, *arr, i + ((*arr)[i] == '\n'));
	result[i + ((*arr)[i] == '\n')] = '\0';
	if ((*arr)[i] == '\0')
	{
		free(*arr);
		*arr = NULL;
		return (result);
	}
	rest = ft_strdup(*arr + i + 1);
	free(*arr);
	*arr = rest;
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*arr[MAX_FD];
	char		*buffer;
	ssize_t		size;
	char		*result;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!new_line_found(arr[fd]))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
			return (free(buffer), free(arr[fd]), arr[fd] = NULL, NULL);
		if (size == 0)
			break ;
		buffer[size] = '\0';
		arr[fd] = fill_line(arr[fd], buffer);
		if (!arr[fd])
			return (free(buffer), NULL);
	}
	free(buffer);
	result = extract_line(&arr[fd]);
	return (result);
}
