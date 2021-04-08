/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:34:17 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/08 20:35:51 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	
	ret = malloc(size * count);
	if (ret)
	{
		ft_bzero(ret, size * count);
		return (ret);
	}
	else
		return (NULL);
}
