/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdwarven <hdwarven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 19:36:16 by hdwarven          #+#    #+#             */
/*   Updated: 2019/02/14 17:27:16 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figures	*take_tail(t_figures **tetr)
{
	t_figures *cur;

	cur = *tetr;
	if (cur)
		while (cur && cur->next)
			cur = cur->next;
	return (cur);
}

void		add2list(t_figures **tetr, char *fig, char bukva)
{
	t_figures	*head;
	t_figures	*tail;

	if ((head = (struct s_figures*)malloc(sizeof(struct s_figures))))
	{
		head->letter = bukva;
		insert2node(head->fig, fig, bukva);
		if (!(*tetr))
		{
			*tetr = head;
			head->head = head;
		}
		else
		{
			tail = take_tail(tetr);
			tail->next = head;
			head->head = tail->head;
		}
		head->next = NULL;
	}
}

void		insert2node(int fig[64][64], char *str, char bukva)
{
	int i;
	int j;
	int count;
	int col;

	col = check_col(str, bukva);
	count = 0;
	i = -1;
	while (str && ++i < 4)
	{
		j = -1;
		if (!check_str(str, bukva) && ++count)
			str += 4;
		while (*str != '\n' && ++j < 64)
		{
			if (*str == '.')
				fig[i][j - col] = 0;
			else if (*str == bukva)
				fig[i - count][j - col] = (int)bukva;
			str++;
		}
		str++;
	}
}

int			get_figure(char *buff, t_figures **tetr)
{
	char		*fig;
	int			i;
	static char	bukva;

	if (!bukva)
		bukva = 'A';
	i = 0;
	fig = duplicate(buff);
	while (fig[i])
	{
		if (fig[i] == '#')
			fig[i] = bukva;
		i++;
	}
	add2list(tetr, fig, bukva);
	free(fig);
	bukva++;
	return (1);
}
