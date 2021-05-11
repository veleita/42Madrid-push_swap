/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:02:25 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/11 17:38:17 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <common.h>

void	simple_error(void)
{
	write(2, "Error\n", 7);
	exit(0);
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks)
	{
		free(stacks->a);
		free(stacks->b);
	}
	free(stacks);
}

void	free_and_error(t_stacks *stacks)
{
	free_stacks(stacks);
	write(2, "Error\n", 7);
	exit(0);
}
