/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:37:30 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/08 17:15:39 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <common.h>
#include <args_cooker.h>
#include <processor.h>

/*
** Iterate through every node in stack a.
** If a number in the current node is found to be smaller than the one in the
** previous node (when it exists), return false.
** Else, return true.
*/

bool	is_ordered(t_list *stack)
{
	while (stack)
	{
		if (stack->prev && (*stack->prev)->content > stack->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	is_empty(t_list *stack)
{
	if (stack->content == 0 && stack->next == NULL)
		return (true);
	else
		return (false);
}

void	checker(t_stacks *stacks)
{
	if (is_ordered(stacks->a) && is_empty(stacks->b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

/*
** Create stacks a and b.
** Read and execute instructions from stdin.
** Check if stack a is ordered and stack b is empty.
*/

int main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*instruction;

	stacks = args_cooker(argc, argv);
	if (!stacks)
		return (-1);
	while (get_next_line(0, &instruction, 5))
	{
		if (process_instruction(instruction, stacks) == -1)
		{
			free(instruction);
			return (-1);
		}
		free(instruction);
	}
	checker(stacks);
	return (0);
}
