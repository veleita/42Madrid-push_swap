/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:39:59 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/07 12:43:38 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	while ((*lst)->next != NULL)
	{
		ft_lstdelone(*lst, del);
		*lst = (*lst)->next;
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
