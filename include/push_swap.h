/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:25:42 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/25 09:39:07 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <common.h>

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
