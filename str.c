/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:31:11 by ndremora          #+#    #+#             */
/*   Updated: 2019/02/14 17:58:07 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*duplicate(const char *src)
{
	char *str;
	char *st;

	str = (char *)malloc(lenght(src) + 1);
	if (str == NULL)
		return (NULL);
	st = str;
	while (*src)
	{
		*str = *src;
		str++;
		src++;
	}
	*str = '\0';
	return (st);
}

size_t	lenght(const char *str)
{
	size_t		i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}
