/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:04:36 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/23 10:59:31 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <libft.h>
# include <unistd.h>

# define VOID 2147483648

typedef struct	s_stacks
{
	long		*a;
	long		*b;
	int			size;
}				t_stacks;

/*
** Error
*/

void		simple_error(void);
void		free_stacks(t_stacks *stacks);
void		free_and_error(t_stacks *stacks);

/*
** Stacks
*/

int get_last(long *stack);
int	get_stack_size(long *stack);

#endif
