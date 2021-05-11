/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:14:21 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/11 13:36:05 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <common.h>
#include <stdlib.h>
#include <fcntl.h>

bool	read_to_buffer(int fd, char **buffer)
{
	int	len;

	len = read(fd, *buffer, BUFFER_SIZE + 1);
	if (len < 0)
		simple_error();
	if (len == 0)
		return (false);
	else
	{
		(*buffer)[len] = '\0';
		return (true);
	}
}

int	empty_file(char **line)
{
	*line = ft_strdup("");
	return (0);
}

int	complete_line(int fd, char *buffer, char *file[NUM_FDS])
{
	char	*tmp;

	while (!ft_strchr(buffer, '\n'))
	{
		if (read_to_buffer(fd, &buffer) == false)
			return (0);
		tmp = ft_strjoin(file[fd], buffer);
		free(file[fd]);
		file[fd] = tmp;
	}
	return (ft_strchr_index(file[fd], '\n'));
}

int	save_line(char **line, char *file[NUM_FDS], int fd, int newline)
{
	char	*tmp;

	*line = ft_substr(file[fd], 0, newline - 1);
	tmp = ft_strdup(&file[fd][newline]);
	free(file[fd]);
	file[fd] = tmp;
	if (*file[fd] == '\0')
		return (0);
	else
		return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*file[NUM_FDS];
	int			newline;

	buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer || !line || fd < 0)
		simple_error();
	if (file[fd] == NULL)
	{
		if (read_to_buffer(fd, &buffer) == false)
			return (empty_file(line));
		file[fd] = ft_strdup(buffer);
	}
	newline = ft_strchr_index(file[fd], '\n');
	if (!newline)
	{
		newline = complete_line(fd, buffer, file);
		if (!newline)
			return (empty_file(line));
	}
	return (save_line(line, file, fd, newline));
}
