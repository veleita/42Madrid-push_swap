/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:25:18 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/16 16:47:54 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

void print_stacks(t_stacks *stacks)
{
	int i;

	ft_putstr("Stack a:");
	i = 0;
	while (i < stacks->size)
	{
		ft_putchar(' ');
		if (stacks->a[i] != VOID)
			ft_putnbr(stacks->a[i]);
		i++;
	}
	ft_putchar('\n');
	ft_putstr("Stack b:");
	i = 0;
	while (i < stacks->size)
	{
		ft_putchar(' ');
		if (stacks->b[i] != VOID)
			ft_putnbr(stacks->b[i]);
		i++;
	}
	ft_putchar('\n');
}
