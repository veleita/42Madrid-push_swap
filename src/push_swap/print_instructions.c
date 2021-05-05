/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:55:02 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/05 20:11:21 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <instructions.h>

int print_instructions(char *main_instruction, char *secondary_instruction)
{
	if (secondary_instruction == NULL ||
			ft_strcmp(main_instruction, secondary_instruction) == 1)
	{
		ft_putstr(main_instruction);
		return (1);
	}
	else
	{
		write(1, &main_instruction, ft_strlen(main_instruction) - 1);
		ft_putchar(main_instruction[0]);
		ft_putchar('\n');
		return (2);
	}
}

void	push_to_a(t_stacks *stacks)
{
	while (is_empty(stacks->b, stacks->size) == false)
	{
		ft_putstr("pa\n");
		do_the_push(stacks->b, stacks->a, stacks->size);
	}
}
