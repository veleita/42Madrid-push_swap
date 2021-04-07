/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:07:19 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/07 14:03:40 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{

	lstnew = (t_list*)malloc(sizeof(t_list));
	if (!lstnew)
		return (NULL);
	lstnew->content = (void*)content;
	lstnew->prev = NULL;
	lstnew->next = NULL;
	return (lstnew);
}
