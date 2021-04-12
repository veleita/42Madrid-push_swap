/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:07:51 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/12 16:15:52 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	retlen;
	size_t	it;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
		return (ft_strdup(""));
	if ((slen - start) > len)
		retlen = len;
	else
		retlen = slen - start;
	ret = malloc(retlen + 1);
	if (ret != NULL)
	{
		it = 0;
		while (it < retlen)
			ret[it++] = s[start++];
		ret[it] = '\0';
	}
	return (ret);
}
