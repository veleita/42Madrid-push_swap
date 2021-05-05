/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tern_hack_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:56:56 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/05 19:58:41 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *tern_hack_str(bool condition, char *true_str, char *false_str)
{
	if (condition == true)
		return (true_str);
	else
		return (false_str);
}
