/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:25:42 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/07 11:47:41 by mzomeno-         ###   ########.fr       */
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
** Priority
*/

char	set_priority(t_stacks *stacks);

/*
** Get set of instructions
*/

t_list	*get_set_of_instructions_a(long *stack);
t_list	*get_set_of_instructions_b(long *stack);

/*
** Get pairs together
*/

void	get_biggest_pair_together(long *stack, t_list **set_of_ins,
									t_nums *important_numbers);
void	get_smallest_pair_together(long *stack, t_list **set_of_ins,
									t_nums *important_numbers);
void	get_first_next_to_second(long *stack, char stack_id, t_nums *important_numbers,
									t_list **set_of_ins);
void	get_first_to_head(long *stack, t_nums *important_numbers,
							char stack_id, t_list **set_of_ins);
int		get_dist_from_head(long *stack, int aim);
int		get_dist_from_tail(long *stack, int aim);

/*
** Finish!
*/

int print_instructions(char *main_instruction, char *secondary_instruction);
void	push_to_a(t_stacks *stacks);

#endif
