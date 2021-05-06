/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_of_ins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:32:39 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/06 17:44:44 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list	*get_set_of_instructions_a(long *stack)
{
	t_list	*set_of_ins;
	int		it = 10;

	set_of_ins = NULL;
//	while (is_ordered(stack) == false)
	while (it-- > 0)
		get_biggest_pair_together(stack, &set_of_ins);
	return (set_of_ins);
}

t_list	*get_set_of_instructions_b(long *stack)
{
	t_list	*set_of_ins;

	set_of_ins = NULL;
	while (is_rev_ordered(stack) == false)
		get_smallest_pair_together(stack, &set_of_ins);
	return (set_of_ins);
}
