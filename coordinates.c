/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:42:23 by ndremora          #+#    #+#             */
/*   Updated: 2019/02/14 17:32:01 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min_x(t_figures *tetr, int size)
{
	int i;
	int j;
	int count;
	int flag;

	count = 0;
	flag = 0;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (tetr->fig[i][j] != 0)
				flag++;
		}
		if (!flag)
			count++;
		else
			break ;
	}
	return (count);
}

int		min_y(t_figures *tetr, int size)
{
	int i;
	int j;
	int count;
	int flag;

	count = 0;
	flag = 0;
	j = -1;
	while (++j < size)
	{
		i = -1;
		while (++i < size)
		{
			if (tetr->fig[i][j] != 0)
				flag++;
		}
		if (!flag)
			count++;
		else
			break ;
	}
	return (count);
}
