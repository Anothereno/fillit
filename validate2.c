/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:55:36 by ndremora          #+#    #+#             */
/*   Updated: 2019/02/14 17:56:32 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_str(char *str, char bukva)
{
	char	*st;

	st = str;
	if (st)
		while (*st != '\n')
		{
			if (*st == bukva)
				return (1);
			st++;
		}
	return (0);
}

int			check_col(char *str, char bukva)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (i < 4)
	{
		if (str[i] == '.' && str[i + 5] == '.' && str[i + 10] == '.'
			&& str[i + 15] == '.')
			count++;
		if (str[i] == bukva || str[i + 5] == bukva || str[i + 10] == bukva
		|| str[i + 15] == bukva)
			break ;
		i++;
	}
	return (count);
}
