/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:48:29 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/11 18:30:22 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	faults;

	if (!s1 || !s2)
		return (-1);
	faults = 0;
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			faults++;
		s1++;
		s2++;
	}
	while (*(s1++))
		faults++;
	while (*(s2++))
		faults++;
	return (faults);
}
