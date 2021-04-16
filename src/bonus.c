/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:25:18 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/16 12:48:31 by mzomeno-         ###   ########.fr       */
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
		ft_putnbr(stacks->a[i]);
		i++;
	}
	ft_putchar('\n');
	ft_putstr("Stack b:");
	i = 0;
	while (i < stacks->size)
	{
		ft_putchar(' ');
		ft_putnbr(stacks->b[i]);
		i++;
	}
	ft_putchar('\n');
}
