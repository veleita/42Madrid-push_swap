/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:34:38 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/11 12:48:59 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;

	if (c == 0)
		return ((char *)s);
	a = (char)c;
	while (*s)
	{
		if (*s == a)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
