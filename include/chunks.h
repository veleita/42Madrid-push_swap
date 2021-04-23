/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:53:26 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/23 11:22:18 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNKS_H
# define CHUNKS_H

#include <common.h>

void	divide_chunks(t_stacks *stacks);
long	*order_stack(long *stack, int stack_size);

#endif
