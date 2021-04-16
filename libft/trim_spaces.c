/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:28:30 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/16 12:19:44 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*trim_spaces(char *str)
{
	int it;
	int len;
	char *ret;

	it = 0;
	while (str[it] == ' ')
		it++;
	len = 0;
	while (str[it] != ' ' && str[it] != '\0')
	{
		len++;
		it++;
	}
	ret = (char*)malloc(len + 1);
	ret[len] = '\0';
	while (len-- >= 0)
		ret[len] = str[--it];
	return (ret);
}
