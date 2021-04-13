/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:02:25 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/09 13:45:26 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <common.h>

void		simple_error(void)
{
	write(2, "Error\n", 7);
	exit(0);
}

void		*free_and_error(t_stacks *stacks)
{
	if (stacks->a)
		free(stacks->a);
	if (stacks->b)
		free(stacks->b);
	free(stacks);
	write(2, "Error\n", 7);
	exit(0);
}
