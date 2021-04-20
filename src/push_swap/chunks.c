/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 21:09:16 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/21 00:34:39 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_chunk_size(long *stack, int stack_size)
{
	int chunk_size;
	int n_chunks;

	n_chunks = 1;
	chunk_size = stack_size / n_chunks;
	while (chunk_size > (n_chunks * 10))
	{
		n_chunks++;
		chunk_size = stack_size / n_chunks;
	}
	return (chunk_size);
}

static void	search_and_push(int chunk_size, int stack_size, t_stacks *stacks)
{
	int		top_index;
	int		bottom_index;
	int		stack_index;
	
	bottom_index = 0;
	top_index = chunk_size;
	while (top_index < stack_size)
	{	
		while (bottom_index < top_index)
		{
			stack_index = 0;
			while (stack_index < stack_size)
			{
				if (stack[bottom_index] == ordered_stack[stack_index])
				{
					do_the_push();
					ft_putstr("pb\n");
					break ;
				}
				stack_index++;
			}
			bottom_index++;
		}
		top_index += chunk_size;
	}
}

void	divide_chunks(t_stacks *stacks)
{
	int		stack_size;
	int		chunk_size;
	long	*ordered_stack;

	stack_size = get_stack_size(stacks->a);
	chunk_size = get_chunk_size(stacks->a, stack_size);
	ordered_stack = order_stack(stacks->a);
	search_and_push(chunk_size, stack_size, stacks)
}
