/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:02:25 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/07 13:56:07 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	simple_error(void)
{
	write(2, "Error\n", 7);
	return (0);
}

int	free_and_error(t_stacks *stacks)
{
	if (stacks->a)
		ft_lstclear(&stacks->a, ft_set_null);
	if (stacks->b)
		ft_lstclear(&stacks->b, ft_set_null);
	free(stacks);
	return(simple_error());
}
