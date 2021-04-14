/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:37:30 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/12 18:55:09 by mzomeno-         ###   ########.fr       */
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

bool	is_ordered(int *stack, int size)
{
	while (--size)
	{
		stack++;
		if (*(stack - 1) > *stack)
			return (false);
	}
	return (true);
}

bool	is_empty(int *stack, int size)
{
	while (--size)
	{
		if (*(stack++) != 0)
			return (false);
	}
	return (true);
}

void	checker(t_stacks *stacks, int size)
{
	if (is_ordered(stacks->a, size) && is_empty(stacks->b, size))
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
	int		read;

	stacks = args_cooker(argc, argv);
	if (!stacks)
		return (-1);
	read = get_next_line(0, &instruction);
	if (read == -1)
		simple_error();
	while (read >= 0)
	{
		if (process_instruction(instruction, stacks) == -1)
		{
			free(instruction);
			return (-1);
		}
		free(instruction);
		if (read == 0)
			break ;
	}
	checker(stacks, argc - 1);
	free_stacks(stacks);
	return (0);
}
