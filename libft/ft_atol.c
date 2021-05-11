/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:51:05 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/11 12:54:06 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	i;
	int		sign;

	sign = 1;
	i = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		if ('0' <= *(str + 1) && *(str + 1) <= '9')
			i = (i + *str - '0') * 10;
		else
			i += *str - '0';
		str++;
	}
	return (i * sign);
}
