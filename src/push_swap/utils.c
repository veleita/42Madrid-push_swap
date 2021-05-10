/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:39:09 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/10 15:27:47 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		get_dist_from_head(long *stack, int aim)
{
	int	dist;

	dist = 0;
	while (stack[dist] != aim)
		dist++;
	return (dist);
}

int		get_dist_from_tail(long *stack, int aim)
{
	int	dist;
	int	last;

	dist = 0;
	last = get_last(stack);
	while (stack[last - dist] != aim)
		dist++;
	return (dist);
}

int	get_bigger_index(long *stack, long *ordered_stack, int last, int excludes)
{
	int bigger_index;
	int it;

	bigger_index = 0;
	it = 0;
	while (stack[it] != VOID)
	{
		if (stack[it] == ordered_stack[last - excludes])
			bigger_index = it;
		it++;
	}
	return (bigger_index);
}
