/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:37:30 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/15 20:54:19 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <common.h>
#include <args_cooker.h>
#include <processor.h>
#include <bonus.h>

/*
** Iterate through every node in stack a.
** If a number in the current node is found to be smaller than the one in the
** previous node (when it exists), return false.
** Else, return true.
*/

bool	is_ordered(int *stack, int size)
{
	int it;

	it = 0;
	while (it < size)
	{
		if (stack[it] > stack[it + 1])
			return (false);
		it++;
	}
	return (true);
}

bool	is_empty(int *stack, int size)
{
	int it;

	it = 0;
	while (it < size)
	{
		if (stack[it] != 0)
			return (false);
		it++;
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
	bool		verbose;

	verbose = 0;
	if (argv[1][0] == '-')
		if (argv[1][1] == 'v' && argv[1][2] == '\0')
			verbose = 1;
	stacks = args_cooker(argc - verbose, argv);
	if (!stacks)
		return (-1);
	while (get_next_line(0, &instruction) > 0)
	{
		if (verbose)
			print_stacks(stacks, argc - 1);
		if (process_instruction(instruction, stacks, argc) == -1)
		{
			free(instruction);
			return (-1);
		}
		free(instruction);
	}
	checker(stacks, argc - verbose);
	return (0);
}
