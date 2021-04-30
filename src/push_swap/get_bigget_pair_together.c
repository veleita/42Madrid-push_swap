/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:34:34 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/30 17:05:23 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	get_second_to_head(long *stack, int second)
{
	int	dist_from_head;
	int	dist_from_tail;

	dist_from_head = get_dist_from_head(stack, second);
	dist_from_tail = get_dist_from_tail(stack, second);
	if (dist_from_head >= dist_from_tail)
		while (*stack != second)
			do_the_rot(stack);
	else
		while (*stack != second)
			do_the_revrot(stack);
}

void	get_biggest_pair_together(long *stack)
{
	int bigger;
	int second;
	int it;

	bigger = INT_MIN;
	second = INT_MIN;
	it = 0;
	while (stack[it] != VOID)
	{
		if (stack[it] > bigger && (it == 0 || bigger != stack[it - 1]))
		{
			second = bigger;
			bigger = stack[it];
		}
		else if (stack[it] > second)
			second = stack[it];
		it++;
	}
	get_second_to_head(stack, second);
	get_first_next_to_second(stack, first);
}
