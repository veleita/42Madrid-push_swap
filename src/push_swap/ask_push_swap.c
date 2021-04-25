/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 09:14:46 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/25 12:07:15 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <instructions.h>

void	ask_push(t_stacks *stacks, char priority)
{
	if ((stacks->b[0] > stacks->b[1]
		|| (stacks->b[0] != VOID && stacks->b[1] == VOID)
		|| stacks->a[0] == VOID)
		&& (priority == 'a' || stacks->b[0] < stacks->a[0]))
		{
			do_the_push(stacks->b, stacks->a, stacks->size);
			ft_putstr("pa\n");
		}
}

void	ask_swap(t_stacks *stacks, char priority)
{
	bool a_needs;
	bool b_needs;

	a_needs = (stacks->a[0] > stacks->a[1]);
	b_needs = ((stacks->b[0] < stacks->b[1]) && (stacks->b[0] > stacks->b[2]));
	if (priority == 'a' && a_needs == true)
	{
		do_the_swap(stacks->a);
		if (b_needs == true)
		{
			do_the_swap(stacks->b);
			ft_putstr("ss\n");
		}
		else
			ft_putstr("sa\n");
	}
	else if (priority == 'b' && b_needs == true)
	{
		do_the_swap(stacks->b);
		if (a_needs == true)
		{
			do_the_swap(stacks->a);
			ft_putstr("ss\n");
		}
		else
			ft_putstr("sb\n");
	}
}
