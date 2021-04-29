/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:10:08 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/28 14:31:48 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <get_next_line.h>
# include <common.h>

/*
** Main
*/

void	checker(t_stacks *stacks);

/*
** Processor
*/

int		process_instruction(char *instruction, t_stacks *stacks);
void	rotate_ins(char *instruction, t_stacks *stacks);
void	revrotate_ins(char *instruction, t_stacks *stacks);
void	push_ins(char *instruction, t_stacks *stacks);
void	swap_ins(char *instruction, t_stacks *stacks);

#endif
