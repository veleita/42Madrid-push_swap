/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:14:21 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/10 13:18:19 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <common.h>
# include <stdlib.h>
# include <fcntl.h>

// TO DO
// -----
// Control returns
// Add strchr to libft
// Test gnl

bool		read_to_buffer(int fd, char **buffer)
{
	int	len;
	
	len = read(fd, *buffer, BUFFER_SIZE + 1);
	if (len < 0)
		simple_error();
	if (len == 0)
		return (false);
	else
	{
		*buffer[len] = '\0';
		return (true);
	}
}

int			empty_file(char **line)
{
	*line = ft_strdup("");
	return (0);
}

int			complete_line()
{
	bool		read;

	while (!ft_strchr(buffer, '\n'))
	{
		read = read_to_buffer(fd, &buffer);
		if (read == false)
			return (empty_file(line));
		tmp = ft_strjoin(file[fd], buffer);
		free(file[fd]);
		file[fd] = tmp;
	}
}

int			get_next_line(int fd, char **line)
{
	char		*buffer;
	char		*tmp;
	static char	*file[NUM_FDS];
	int			len;

	buffer = (char*)ft_calloc(BUFFER_SIZE + 1);
	if (!buffer || !line || fd < 0)
		simple_error();
	if (file[fd] == NULL)
	{
		read_to_buffer(fd, &buffer);
		file[fd] = ft_strdup(buffer);
	}
	else
	{
		newline = ft_strchr(file[fd], '\n');
		if (newline)
		{
			*line = ft_substr(file[fd], 0, newline - 1);
			tmp = ft_strdup(&file[fd][newline]);
			free(file[fd]);
			file[fd] = tmp;
		}
		else
			complete_line();
	}
}
