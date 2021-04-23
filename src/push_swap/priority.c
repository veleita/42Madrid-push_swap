/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:38:36 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/23 17:03:55 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	count_fails(long *stack)
{
	int it;
	int fails;

	fails = 0;
	it = 0;
	while (stack[++it] != VOID)
	{
		if (stack[it] < stack[it - 1])
			fails++;
	}
	return (fails);
}

char	set_priority(t_stacks *stacks)
{
	if (count_fails(stacks->a) > count_fails(stacks->b))
		return ('a');
	else
		return ('b');
}
