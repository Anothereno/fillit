/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:09:34 by ndremora          #+#    #+#             */
/*   Updated: 2019/02/14 18:10:06 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(int fig[64][64], int size)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (fig[i][j] == 0)
			{
				write(1, ".", 1);
				continue;
			}
			c = (char)fig[i][j];
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
}

int		print_error(int flag, t_figures *tetr)
{
	if (flag || !tetr)
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (1);
}

void	fillit_usage(char argv[0])
{
	ft_putstr(":usage ");
	ft_putstr(&argv[0]);
	ft_putstr(" [fillit_file]\n");
}
