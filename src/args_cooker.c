/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_cooker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:33:54 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/07 13:55:06 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <args_cooker.h>
#include <common.h>

/*
** If there are no arguments, return cleanly
** If any of the characters in an argument is not a digit, return with an error
** If any of the characters in an argument is bigger than the maximum value for
** an int (2.147.483.647) or smaller than the minimum value (-2.147.483.648),
** return with an error.
*/

t_stacks *args_cooker(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	stacks = malloc(sizeof(*stacks));
	while (*argv)
	{
		if (ft_str_isdigit(*argv))
			return(free_and_error(stacks));
		if (ft_strlen(*argv) > 11 &&
			(ft_atoi(*argv) > INT_MAX || ft_atoi(*argv) < INT_MIN)
			return(free_and_error(stacks));
		ft_lstadd_back(&(stack->a), ft_lstnew(ft_atoi(*argv))); // THIS CAN BE PROBLEMATIC
		argv++;
	}
	stacks->b = ft_lstnew(0); // THIS TOO
	return (stacks);
}
