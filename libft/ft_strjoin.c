/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:53:34 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/12 16:59:52 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ret != NULL)
	{
		i = -1;
		while (s1[++i])
			ret[i] = s1[i];
		j = -1;
		while (s2[++j])
			ret[i++] = s2[j];
		ret[i] = '\0';
	}
	return (ret);
}
