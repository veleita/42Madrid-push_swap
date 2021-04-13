/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_cooker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:33:54 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/09 14:09:47 by mzomeno-         ###   ########.fr       */
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

t_stacks	*create_stacks(int argc)
{
	t_stacks	*stacks;

	stacks = (t_stacks*)malloc(sizeof(*stacks));
	stacks->a = ft_calloc(argc - 1, sizeof(int));
	stacks->b = ft_calloc(argc - 1, sizeof(int));
	return (stacks);
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
	int			i;

	if (argc == 1)
		return (0);
	stacks = create_stacks(argc);
	i = 0;
	while (argv[++i])
	{
		check_args(argv, i, stacks);
		stacks->a[i - 1] = ft_atoi(argv[i]);
	}
	return (stacks);
}
