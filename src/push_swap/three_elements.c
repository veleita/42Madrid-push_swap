/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:32:41 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/10 17:10:52 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <instructions.h>

static void	smaller_first(long *stack, long	*ordered_stack)
{
	if (stack[1] == ordered_stack[2])
	{
		do_the_rot(stack);
		ft_putstr("ra\n");
		do_the_swap(stack);
		ft_putstr("sa\n");
	}
}

static void	mid_first(long *stack, long	*ordered_stack)
{
	if (stack[1] == ordered_stack[0])
	{
		do_the_swap(stack);
		ft_putstr("sa\n");
	}
	else
	{
		do_the_revrot(stack);
		ft_putstr("rra\n");
	}
}

static void	bigger_first(long *stack, long	*ordered_stack)
{
	if (stack[1] == ordered_stack[0])
	{
		do_the_revrot(stack);
		ft_putstr("rra\n");
		do_the_swap(stack);
		ft_putstr("sa\n");
	}
	else
	{
		do_the_rot(stack);
		ft_putstr("ra\n");
	}
}

void		order_three(long *stack)
{
	long	*ordered_stack;

	ordered_stack = order_stack(stack, 4);
	if (stack[0] == ordered_stack[0])
		smaller_first(stack, ordered_stack);
	else if (stack[0] == ordered_stack[1])
		mid_first(stack, ordered_stack);
	else
		bigger_first(stack, ordered_stack);
}
