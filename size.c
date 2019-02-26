/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:27:23 by ndremora          #+#    #+#             */
/*   Updated: 2019/02/14 17:13:40 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tab_size(int count)
{
	int i;

	i = 2;
	while ((i * i) < (count * 4))
		i++;
	return (i);
}

int		sizer(t_figures *head)
{
	t_figures	*cur;
	int			count;

	count = 0;
	cur = head;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return (tab_size(count));
}
