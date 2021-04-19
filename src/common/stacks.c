/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:50:58 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/19 16:11:00 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

int get_last(long *stack)
{
	long	last;
	int		index;
	
	index = 0;
	while (stack[index] != VOID)
		index++;
	last = index - 1;
	return (last);
}
