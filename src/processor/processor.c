/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:31:10 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/19 16:17:41 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <processor.h>
#include <common.h>
#include <libft.h>

int	process_instruction(char *instruction, t_stacks *stacks)
{
	char *trimmed_ins;

	trimmed_ins = trim_spaces(instruction);
	if (ft_strlen(trimmed_ins) > 3)
		free_and_error(stacks);
	if (*instruction == 's')
		swap_ins(trimmed_ins, stacks);
	else if (*instruction == 'p')
		push_ins(trimmed_ins, stacks);
	else if (*instruction == 'r')
		rotate_ins(trimmed_ins, stacks);
	else
		free_and_error(stacks);
	return (1);
}
