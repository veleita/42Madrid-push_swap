/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:50:58 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/11 16:02:14 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

bool	is_rev_ordered(long *stack)
{
	int	it;

	it = 0;
	while (stack[++it] != VOID)
	{
		if (stack[it] > stack[it - 1])
			return (false);
	}
	return (true);
}

bool	is_ordered(long *stack)
{
	int	it;

	it = 0;
	while (stack[++it] != VOID)
	{
		if (stack[it] < stack[it - 1])
			return (false);
	}
	return (true);
}

bool	is_empty(long *stack, int size)
{
	int	it;

	it = 0;
	while (it < size)
	{
		if (stack[it] != VOID)
			return (false);
		it++;
	}
	return (true);
}

int	get_last(long *stack)
{
	int		last;
	int		index;

	index = 0;
	while (stack[index] != VOID)
		index++;
	last = index - 1;
	return (last);
}

int	get_stack_size(long *stack)
{
	int	size;

	size = 0;
	while (stack[size] != VOID)
		size++;
	return (size);
}
