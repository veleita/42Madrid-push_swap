/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:09:17 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/09 12:58:40 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

/*
** Is_something?
*/

bool	ft_isdigit(char c);
bool	ft_str_isdigit(char *str);

/*
** Len
*/

size_t	ft_strlen(const char *str);

/*
** Data type transformation
*/

int		ft_atoi(const char *str);
long	ft_atol(const char *str);

/*
 * Initialize
*/

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

/*
** Lists
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *newlst);
t_list	*ft_lstlast(t_list *lst);

#endif
