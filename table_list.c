/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdwarven <hdwarven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:12:20 by hdwarven          #+#    #+#             */
/*   Updated: 2019/02/14 18:17:50 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_size(t_figures *tetr, int size)
{
	int i;
	int j;
	int count;

	count = 0;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (tetr->fig[i][j] == tetr->letter)
				count++;
		}
	}
	if (count != 4)
		return (0);
	return (1);
}

t_field	*create_new_tab(t_figures *tetr)
{
	t_field	*node;
	int		i;
	int		j;

	i = -1;
	node = (t_field*)malloc(sizeof(t_field));
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
			node->fig[i][j] = 0;
	}
	node->size = sizer(tetr->head);
	return (node);
}

void	clearmap(t_field *tab, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			tab->fig[i][j] = 0;
	}
}

void	clear_prev_map(t_field *tab, char c, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (tab->fig[i][j] >= c)
				tab->fig[i][j] = 0;
	}
}

int		insert2tab(t_figures *tetr, t_field *tab)
{
	int i;
	int j;

	i = -1;
	while (++i < tab->size)
	{
		j = -1;
		while (++j < tab->size)
			tab->fig[i][j] += tetr->fig[i][j];
	}
	return (1);
}
