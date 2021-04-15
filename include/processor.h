/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:53:34 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/15 20:28:03 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESSOR_H
# define PROCESSOR_H

# include <common.h>

int		process_instruction(char *instruction, t_stacks *stacks, int args);
void	rotate_ins(char *instruction, t_stacks *stacks, int size);
void	revrotate_ins(char *instruction, t_stacks *stacks, int size);
void	push_ins(char *instruction, t_stacks *stacks, int size);
void	swap_ins(char *instruction, t_stacks *stacks);

#endif
