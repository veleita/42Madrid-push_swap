/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:11:50 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/30 17:59:28 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

void	do_the_rot(long *stack);
void	do_the_revrot(long *stack);
void	do_the_push(long *src, long *dst, int size);
void	do_the_swap(long *stack);

#endif
