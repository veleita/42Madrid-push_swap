/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:55:02 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/11 13:03:57 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <instructions.h>

static char	*join_instructions(char *ins1)
{
	char	*joined;
	int		len;

	len = ft_strlen(ins1);
	joined = (char *)malloc(len);
	joined[len] = '\0';
	len--;
	joined[len] = '\n';
	while (len-- >= 0)
	{
		joined[len] = ins1[0];
	}
	return (joined);
}

int	print_instructions(char *main_instruction, char *secondary_instruction)
{
	char	*joined;

	if (secondary_instruction == NULL
		|| ft_strcmp(main_instruction, secondary_instruction) > 1)
	{
		ft_putstr(main_instruction);
		return (1);
	}
	else
	{
		joined = join_instructions(main_instruction);
		ft_putstr(joined);
		free(joined);
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
