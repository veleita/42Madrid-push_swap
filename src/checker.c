/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:37:30 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/03 14:22:14 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

/*
** Create stacks a and b.
** Read and execute instructions from stdin.
** Check if stack a is ordered and stack b is empty.
*/
int main(int argc, char **argv)
{
	t_stacks	stacks;
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
