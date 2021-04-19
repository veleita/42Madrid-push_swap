/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:57:05 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/19 23:16:00 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <processor.h>
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
	while (stack[index] != stack[last])
	{
		stack[index] = stack[index + 1];
		index++;
	}
	stack[last] = save;
}
