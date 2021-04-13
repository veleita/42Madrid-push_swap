/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:04:36 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/10 12:25:27 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <libft.h>
# include <unistd.h>

typedef struct	s_stacks
{
	int		*a;
	int		*b;
}				t_stacks;

/*
** Error
*/

void		simple_error(void);
void		*free_and_error(t_stacks *stacks);

#endif
