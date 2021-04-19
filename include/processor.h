/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:53:34 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/19 13:15:10 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESSOR_H
# define PROCESSOR_H

# include <common.h>

int		process_instruction(char *instruction, t_stacks *stacks);
void	rotate_ins(char *instruction, t_stacks *stacks);
void	do_the_rot(long *stack);
void	revrotate_ins(char *instruction, t_stacks *stacks);
void	do_the_revrot(long *stack);
void	push_ins(char *instruction, t_stacks *stacks);
void	do_the_push(long *src, long *dst, int size);
void	swap_ins(char *instruction, t_stacks *stacks);
void	do_the_swap(long *stack);

#endif
