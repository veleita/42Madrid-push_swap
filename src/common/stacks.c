/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:50:58 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/23 10:59:11 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

int get_last(long *stack)
{
	long	last;
	int		index;
	
	index = 0;
	while (stack[index] != VOID)
		index++;
	last = index - 1;
	return (last);
}

int	get_stack_size(long *stack)
{
	int size;

	size = 0;
	while (stack[size] != VOID)
		size++;
	return (size);
}
