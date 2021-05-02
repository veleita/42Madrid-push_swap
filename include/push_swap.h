/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:25:42 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/02 17:12:00 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <common.h>

typedef struct	s_ins
{
	char		*simple_ins;
	char		*double_ins;
	void		(*instruction)(long*);
}				t_ins;

/*
** Chunks
*/

int		divide_chunks(t_stacks *stacks);
long	*order_stack(long *stack, int stack_size);

/*
** Algorithm
*/

char	set_priority(t_stacks *stacks);
void	ask_push(t_stacks *stacks, char priority);
void	ask_swap(t_stacks *stacks, char priority);
void	ask_rotate(t_stacks *stacks, char priority);
void	ask_rev_rotate(t_stacks *stacks, char priority, int chunk_size);

#endif
