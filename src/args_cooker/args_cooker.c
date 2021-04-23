/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_cooker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:33:54 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/23 10:03:44 by mzomeno-         ###   ########.fr       */
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

void		check_args(char **argv, int i, t_stacks *stacks)
{
	int	j;

	if (ft_str_isdigit(argv[i]) == false && argv[i][0] != '-')
		free_and_error(stacks);
	if (is_small_num(argv[i]) == false)
		free_and_error(stacks);
	j = i;
	while (ft_strcmp(argv[j--], argv[0]))
		if (ft_strcmp(argv[j], argv[i]) == 0)
			free_and_error(stacks);
}

t_stacks	*create_stacks(int args)
{
	t_stacks	*stacks;
	int			size;

	size = args * 2 + 1;
	stacks = (t_stacks*)malloc(sizeof(*stacks));
	stacks->a = (long*)malloc(size * sizeof(long));
	stacks->b = (long*)malloc(size * sizeof(long));
	while (size-- >= 0)
	{
		stacks->a[size] = VOID;
		stacks->b[size] = VOID;
	}
	stacks->size = args;
	return (stacks);
}

/*
** If there are no arguments, return cleanly
** If any of the characters in an argument is not a digit, return with an error
** If any of the characters in an argument is bigger than the maximum value for
** an int (2.147.483.647) or smaller than the minimum value (-2.147.483.648),
** return with an error.
*/

t_stacks *args_cooker(int argc, int flags, char **argv)
{
	t_stacks	*stacks;
	int			i;

	if (argc == 1)
		return (0);
	stacks = create_stacks(argc - flags - 1);
	i = flags;
	while (argv[++i])
	{
		check_args(argv, i, stacks);
		stacks->a[i - (1 + flags)] = ft_atoi(argv[i]);
	}
	return (stacks);
}
