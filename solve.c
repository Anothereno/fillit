/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdwarven <hdwarven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:25:24 by hdwarven          #+#    #+#             */
/*   Updated: 2019/02/14 18:41:53 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve(t_figures *tetr)
{
	static t_field	*tab;

	if (!tab)
		tab = create_new_tab(tetr);
	while (!combinator(tetr, tab))
	{
		tab->size++;
		clearmap(tab, tab->size);
		set2default(tetr->head, tab->size);
	}
	print_map(tab->fig, tab->size);
	clear_tetr(tetr);
	if (tab)
		free(tab);
}

int		combinator(t_figures *tetr, t_field *tab)
{
	while (try2place(tetr, tab) || try2move_x(tetr, tab)
	|| try2move_y(tetr, tab))
	{
		if (!try2place(tetr, tab) && try2move_x(tetr, tab))
			do_x(tetr, tab);
		else if (!try2place(tetr, tab) && try2move_y(tetr, tab))
			do_y(tetr, tab);
		if (place2(tetr, tab))
		{
			if (tetr->next && combinator(tetr->next, tab))
				return (1);
			else if (!tetr->next)
				return (1);
			else if (!try2move_y(tetr, tab) && !try2move_x(tetr, tab))
				return (0);
		}
	}
	return (0);
}

int		try2place(t_figures *tetr, t_field *tab)
{
	int i;
	int j;

	i = -1;
	if (!check_size(tetr, tab->size))
		return (0);
	while (++i < tab->size)
	{
		j = -1;
		while (++j < tab->size)
		{
			if ((tab->fig[i][j] + tetr->fig[i][j] > 91))
				return (0);
		}
	}
	return (1);
}

int		place2(t_figures *tetr, t_field *tab)
{
	if (try2place(tetr, tab))
	{
		insert2tab(tetr, tab);
		return (1);
	}
	return (0);
}
