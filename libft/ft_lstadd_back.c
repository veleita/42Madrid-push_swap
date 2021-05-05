/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:59:19 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/05 21:32:30 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	if (lst && *lst && newlst)
	{
		if (!(*lst)->next)
			(*lst)->next = newlst;
		else
		{
			ft_lstlast(*lst)->next = newlst;
		}
	}
	else if (lst && newlst)
		*lst = newlst;
}
