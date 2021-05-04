/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_smaller_pair_together.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:34:21 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/04 19:04:02 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	get_first_next_to_second(long *stacks, char priority,
									int first, t_list *instructions)
{
	int	dist_from_head;
	int	dist_from_tail;

	dist_from_head = get_dist_from_head(stack, first);
	dist_from_tail = get_dist_from_tail(stack, first);
	if (dist_from_head >= dist_from_tail)
	{
		while (*(stack + 1) != first)
		{
			ft_lstadd_back(&instructions, &do_the_swap());
			ft_lstadd_back(&instructions, &do_the_revrot());
		}
	}
	else if (*(stack + 1) != first)
		{
			ft_lstadd_back(&instructions, &do_the_revrot());
			ft_lstadd_back(&instructions, &do_the_swap());
		}
	}
}

void	get_second_to_head(long *stack, int second)
{
	int	dist_from_head;
	int	dist_from_tail;

	dist_from_head = get_dist_from_head(stack, second);
	dist_from_tail = get_dist_from_tail(stack, second);
	if (dist_from_head >= dist_from_tail)
		while (*stack != second)
			ft_lstadd_back(&set_of_ins, ft_lstnew(assign_rot_a()));
	else
		while (*stack != second)
			ft_lstadd_back(&set_of_ins, ft_lstnew(assign_revrot_a()));
}
