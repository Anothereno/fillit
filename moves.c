/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:19:41 by ndremora          #+#    #+#             */
/*   Updated: 2019/02/14 17:38:45 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	move_x(t_figures *tetr, int size)
{
	int i;
	int j;

	i = size;
	while (--i >= 0)
	{
		j = size;
		while (--j >= 0)
		{
			if (j == 0)
			{
				tetr->fig[i][j] = 0;
				continue;
			}
			tetr->fig[i][j] = tetr->fig[i][j - 1];
		}
	}
}

void	move_y(t_figures *tetr, int size)
{
	int i;
	int j;

	i = size;
	while (--i >= 0)
	{
		j = size;
		while (--j >= 0)
		{
			if (i == 0)
			{
				tetr->fig[i][j] = 0;
				continue;
			}
			tetr->fig[i][j] = tetr->fig[i - 1][j];
		}
	}
}

int		try2move_x(t_figures *tetr, t_field *tab)
{
	int i;
	int max_x;
	int j;

	if (!check_size(tetr, tab->size))
		return (0);
	max_x = 0;
	i = -1;
	while (++i < tab->size)
	{
		j = -1;
		while (++j < tab->size)
			if (tetr->fig[i][j] != 0)
				if (j > max_x)
					max_x = j;
	}
	if (max_x + 1 < tab->size)
		return (1);
	return (0);
}

int		try2move_y(t_figures *tetr, t_field *tab)
{
	int i;
	int max_y;
	int j;

	if (!check_size(tetr, tab->size))
		return (0);
	max_y = 0;
	i = -1;
	while (++i < tab->size)
	{
		j = -1;
		while (++j < tab->size)
			if (tetr->fig[i][j] != 0)
				if (i > max_y)
					max_y = i;
	}
	if (max_y + 1 < tab->size)
		return (1);
	return (0);
}
