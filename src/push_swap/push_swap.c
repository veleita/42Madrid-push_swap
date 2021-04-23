/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:03:59 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/23 12:49:36 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <chunks.h>
#include <args_cooker.h>

void	push_swap(t_stacks *stacks)
{
	divide_chunks(stacks);
	ft_putstr("END\n");
	return ;
}

int		main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = args_cooker(argc, 0, argv);
	if (!stacks)
		return (-1);
	push_swap(stacks);
	return (0);
}
