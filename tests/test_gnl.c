/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:45:01 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/12 17:03:48 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = 0;
	char *line;

	while (get_next_line(fd, &line))
		printf("line = -> %s <-\n", line);
	printf("line = -> %s <-\n", line);
	return (0);
}
