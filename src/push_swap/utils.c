/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:39:09 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/05 15:53:40 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		get_dist_from_head(long *stack, int aim)
{
	int	dist;

	dist = 0;
	while (stack[dist] != aim)
		dist++;
	return (dist);
}

int		get_dist_from_tail(long *stack, int aim)
{
	int	dist;
	int	last;

	dist = 0;
	last = get_last(stack);
	while (stack[last - dist] != aim)
		dist++;
	return (dist);
}
