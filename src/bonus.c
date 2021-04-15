/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:25:18 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/15 19:29:51 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>
#include <stdio.h>

void print_stacks(t_stacks *stacks, int argc)
{
	int i;

	printf("Stack a:");
	i = 0;
	while (i < argc)
	{
		printf(" %d", stacks->a[i]);
		i++;
	}
	printf("\n");
	printf("Stack b:");
	i = 0;
	while (i < argc)
	{
		printf(" %d", stacks->b[i]);
		i++;
	}
}
