/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:39:23 by ndremora          #+#    #+#             */
/*   Updated: 2019/02/14 17:40:17 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clear_tetr(t_figures *tetr)
{
	t_figures		*cur;

	if (tetr && tetr->head)
	{
		tetr = tetr->head;
		while (tetr)
		{
			cur = tetr;
			tetr = tetr->next;
			free(cur);
			cur = NULL;
		}
	}
}

void	set2default(t_figures *tetr, int size)
{
	t_figures *ptr;

	ptr = tetr;
	while (ptr)
	{
		shift(ptr, min_x(ptr, size), min_y(ptr, size), size);
		ptr = ptr->next;
	}
}
