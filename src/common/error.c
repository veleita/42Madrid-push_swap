/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:02:25 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/08 20:04:33 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <common.h>

int	simple_error(void)
{
	write(2, "Error\n", 7);
	return (0);
}

t_stacks	*free_and_error(t_stacks *stacks)
{
	if (stacks->a)
		ft_lstclear(&stacks->a, free);
	if (stacks->b)
		ft_lstclear(&stacks->b, free);
	free(stacks);
	write(2, "Error\n", 7);
	return(0);
}
