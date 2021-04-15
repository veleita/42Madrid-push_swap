/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:22:37 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/15 20:23:55 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

void	do_the_swap(int *stack);
void	do_the_push(int *src, int *dst, int size);
void	do_the_revrot(int *stack, int size);
void	do_the_rot(int *stack, int size);

#endif
