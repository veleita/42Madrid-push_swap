/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:09:17 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/07 15:02:29 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
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

int		ft_intlen(int i);
size_t	ft_strlen(const char *str);

/*
** Cpy
*/

void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
** Cmp
*/

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** Data type transformation
*/

char	*ft_itoa(int i);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);

/*
** String manipulation
*/

char	*ft_strjoin(char const *s1, char const *s2);

/*
** Puts
*/

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnstr(char *str, int n);
void	ft_putnbr(int n);

/*
** Initialize
*/

void	*ft_memset(void *b, long c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

/*
** Find
*/

char	*ft_strchr(const char *s, int c);
int		ft_strchr_index(char *s, char c);

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
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

/*
** Ternary
*/

char *tern_hack_str(bool condition, char *true_str, char *false_str);

#endif
