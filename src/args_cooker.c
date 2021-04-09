/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_cooker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:33:54 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/09 13:23:16 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <args_cooker.h>
#include <common.h>
#include <libft.h>

static bool	is_small_num(char *num)
{
	if (ft_strlen(num) < 11)
	   return (true);
	else if (ft_strlen(num) == 11 &&
		(ft_atol(num) <= INT_MAX && ft_atol(num) >= INT_MIN))
		return(true);
	else
		return (false);
}

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
	int			*number;

	if (argc == 1)
		return (0);
	stacks = (t_stacks*)ft_calloc(2, sizeof(t_list));
	stacks->a = NULL;
	while (*(++argv))
	{
		if (ft_str_isdigit(*argv) == false && **argv != '-')
			return(free_and_error(stacks));
		if (is_small_num(*argv) == false)
			return(free_and_error(stacks));
		number = malloc(sizeof(int));
		*number = ft_atoi(*argv);
		ft_lstadd_back(&(stacks->a), ft_lstnew(number)); // THIS CAN BE PROBLEMATIC
	}
	stacks->b = ft_lstnew(0); // THIS TOO
	return (stacks);
}
