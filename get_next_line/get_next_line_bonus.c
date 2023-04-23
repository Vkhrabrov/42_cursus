/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:01:02 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/04/23 20:16:19 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

char	*storage_update(char **storage, int i)
{
	char	*temp;

	temp = ft_strdup(&(*storage)[i]);
	if (!temp)
		return (NULL);
	free(*storage);
	*storage = temp;
	return (*storage);
}

char	*filling_storage(int fd, char *storage, char *buffer)
{
	size_t	storage_size;
	char	*new_storage;
	int		num_bytes;

	storage_size = 0;
	num_bytes = 1;
	*buffer = '\0';
	while (num_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if (num_bytes == -1)
		{
			free(storage);
			storage = NULL;
			return (NULL);
		}
		buffer[num_bytes] = '\0';
		new_storage = ft_strjoin(storage, buffer);
		free(storage);
		storage = new_storage;
	}
	return (storage);
}

char	*filling_line(char *storage, char *line, char **storage_ptr)
{
	size_t	i;

	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\n' || storage[i] == '\0')
	{
		if (ft_strchr(storage, '\n'))
			i++;
		line = malloc(sizeof(char) * (i + 1));
		if (!line)
			return (line);
		ft_strlcpy(line, storage, i + 1);
	}
	*storage_ptr = storage_update(&storage, i);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*storage[FD];
	int			index;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	index = fd % FD;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = NULL;
	storage[index] = filling_storage(fd, storage[index], buffer);
	if (!storage[index] || *storage[index] == '\0')
	{
		free (storage[index]);
		storage[index] = NULL;
		free(buffer);
		return (NULL);
	}
	line = filling_line(storage[index], line, &storage[index]);
	free(buffer);
	return (line);
}
