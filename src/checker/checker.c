/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:37:30 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/11 16:22:53 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <common.h>
#include <args_cooker.h>
#include <bonus.h>
#include <stdio.h>

/*
** Iterate through every node in stack a.
** If a number in the current node is found to be smaller than the one in the
** previous node (when it exists), return false.
** Else, return true.
*/

void	checker(t_stacks *stacks)
{
	if (is_ordered(stacks->a) && is_empty(stacks->b, stacks->size * 2))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static void	executor(t_stacks *stacks, bool verbose)
{
	char	*instruction;

	instruction = NULL;
	while (get_next_line(0, &instruction) >= 0)
	{
		if (!(*instruction))
			break ;
		ft_putstr(instruction);
		ft_putchar('\n');
		if (process_instruction(instruction, stacks) == -1)
		{
			free(instruction);
			return ;
		}
		free(instruction);
		instruction = NULL;
		if (verbose)
			print_stacks(stacks);
	}
}

static bool	set_verbose(int argc, char **argv)
{
	bool	verbose;

	verbose = false;
	if (argc > 1 && argv[1][0] == '-')
		if (argv[1][1] == 'v' && argv[1][2] == '\0')
			verbose = true;
	return (verbose);
}

/*
** Create stacks a and b.
** Read and execute instructions from stdin.
** Check if stack a is ordered and stack b is empty.
*/

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	bool		verbose;

	verbose = set_verbose(argc, argv);
	stacks = args_cooker(argc, verbose, argv);
	if (!stacks)
		return (-1);
	if (verbose)
		print_stacks(stacks);
	executor(stacks, verbose);
	checker(stacks);
	return (0);
}
