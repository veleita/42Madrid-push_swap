/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:04:36 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/08 20:05:06 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <libft.h>
# include <unistd.h>

typedef struct	s_stacks
{
	t_list		*a;
	t_list		*b;
}				t_stacks;

/*
** Error
*/

int			simple_error(void);
t_stacks	*free_and_error(t_stacks *stacks);

#endif
