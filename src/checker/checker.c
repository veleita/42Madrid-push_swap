/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:37:30 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/23 14:16:54 by mzomeno-         ###   ########.fr       */
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

bool	is_empty(long *stack, int size)
{
	int it;

	it = 0;
	while (it < size)
	{
		if (stack[it] != VOID)
			return (false);
		it++;
	}
	return (true);
}

static bool	is_ordered(long *stack, int size)
{
	int it;

	it = 0;
	while (it < size - 1)
	{
		if (stack[it] > stack[it + 1])
			return (false);
		it++;
	}
	if (is_empty(&(stack[it + 1]), size))
		return (true);
	else
		return (false);
}

void		checker(t_stacks *stacks)
{
	if (is_ordered(stacks->a, stacks->size) && is_empty(stacks->b, stacks->size * 2))
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
	if (argc > 1 && argv[1][0] == '-')
		if (argv[1][1] == 'v' && argv[1][2] == '\0')
			verbose = 1;
	stacks = args_cooker(argc, verbose, argv);
	if (!stacks)
		return (-1);
	if (verbose)
		print_stacks(stacks);
	while (get_next_line(0, &instruction) >= 0)
	{
		ft_putchar('\n');
		if (ft_strcmp(instruction, "END") == 0)
			break ;
		ft_putstr(instruction);
		if (process_instruction(instruction, stacks) == -1)
		{
			free(instruction);
			return (-1);
		}
		free(instruction);
		if (verbose)
			print_stacks(stacks);
	}
	checker(stacks);
	return (0);
}
