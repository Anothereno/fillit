/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:36:32 by ndremora          #+#    #+#             */
/*   Updated: 2019/02/14 17:37:48 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	do_x(t_figures *tetr, t_field *tab)
{
	move_x(tetr, tab->size);
	clear_prev_map(tab, tetr->letter, tab->size);
	set2default(tetr->next, tab->size);
}

void	do_y(t_figures *tetr, t_field *tab)
{
	shift(tetr, 0, min_y(tetr, tab->size), tab->size);
	move_y(tetr, tab->size);
	clear_prev_map(tab, tetr->letter, tab->size);
	set2default(tetr->next, tab->size);
}

void	shift(t_figures *ptr, int y, int x, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ptr->fig[i][j] = ptr->fig[i + y][j + x];
	}
}
