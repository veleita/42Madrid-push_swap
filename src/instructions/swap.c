/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:40:45 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/19 23:21:57 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <instructions.h>
#include <common.h>

void	do_the_swap(long *stack)
{
	int save;

	if (stack[1] == VOID)
		return ;
	save = stack[0];
	stack[0] = stack[1];
	stack[1] = save;
}
