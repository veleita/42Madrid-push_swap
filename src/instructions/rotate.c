/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:57:05 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/05 18:25:31 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

void	do_the_rot(long *stack)
{
	int 	save;
	int		index;
	int		last;

	if (*stack == VOID)
		return ;
	last = get_last(stack);
	save = stack[0];
	index = 0;
	while (index < last)
	{
		stack[index] = stack[index + 1];
		index++;
	}
	stack[last] = save;
}
