/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:03:59 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/11 18:30:45 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <common.h>
#include <instructions.h>
#include <args_cooker.h>

static void	order_two(long *stack)
{
	if (*stack > *(stack + 1))
	{
		do_the_swap(stack);
		ft_putstr("sa\n");
	}
}

static bool	is_already_ordered(long *stack)
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

void	push_swap(t_stacks *stacks)
{
	int		stack_size;

	stack_size = get_stack_size(stacks->a);
	if (stack_size == 2)
		order_two(stacks->a);
	else if (stack_size == 3)
		order_three(stacks->a);
	else if (stack_size == 5)
		order_five(stacks);
	else
		normal_insertion(stacks, stack_size);
	return ;
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = args_cooker(argc, 0, argv);
	if (!stacks)
		return (1);
	if (is_already_ordered(stacks->a) == true)
	{
		free_stacks(stacks);
		return (0);
	}
	push_swap(stacks);
	free_stacks(stacks);
	return (0);
}
