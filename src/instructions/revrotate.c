/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:58:57 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/19 23:15:24 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <instructions.h>
#include <common.h>

void	do_the_revrot(long *stack)
{
	int index;
	long last;

	if (*stack == VOID)
		return ;
	index = get_last(stack);
	last = stack[index];
	while (index)
	{
		stack[index] = stack[index - 1];
		index--;
	}
	stack[0] = last;
}
