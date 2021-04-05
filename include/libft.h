/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:08:17 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/03 14:09:54 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct		s_list
{
	void		*content;
	struct s_list	*prev;
	struct s_list	*next;
}			t_list;

bool	ft_str_isdigit(char *str);
int	ft_atoi(char *str);

#endif
