/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:25:42 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/10 15:37:42 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <common.h>

typedef struct	s_nums
{
	int 		first;
	int 		second;
	int 		top;
}				t_nums;

/*
** Chunks
*/

void	divide_chunks(t_stacks *stacks);
long	*order_stack(long *stack, int stack_size);

/*
** Order elements
*/

void		normal_insertion(t_stacks *stacks, int stack_size);
void		order_three(long *stack);
void		order_five(t_stacks *stacks);

/*
** Utils
*/

int		get_dist_from_head(long *stack, int aim);
int		get_dist_from_tail(long *stack, int aim);
int		get_bigger_index(long *stack, long *ordered_stack, int last,
						int excludes);
#endif
