/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:26:25 by makamins          #+#    #+#             */
/*   Updated: 2024/12/04 17:24:13 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_first_line(int fd, char *buffer, char *line)
{
	int		read_line;
	char	*temporary;	

	read_line = 1;
	while (read_line != 0)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line < 0)
			break ;
		buffer[read_line] = '\0';
		if (!line)
			line = ft_strdup("");
		temporary = line;
		line = ft_strjoin(temporary, buffer);
		free(temporary);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if ((read_line == 0 && *line == '\0') || read_line < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*extract_line(char *rest)
{
	char	*line;
	int		i;

	if (!rest || *rest == '\0')
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	line = ft_substr(rest, 0, i);
	return (line);
}

static char	*update_rest(char *rest)
{
	char	*new_rest;
	int		i;

	if (!rest)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	if (rest[i] == '\0')
	{
		free(rest);
		return (NULL);
	}
	new_rest = ft_strdup(rest + i);
	free(rest);
	return (new_rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	rest = read_first_line(fd, buffer, rest);
	free(buffer);
	if (!rest)
		return (NULL);
	line = extract_line(rest);
	if (!line)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	rest = update_rest(rest);
	return (line);
}
