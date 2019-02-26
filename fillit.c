/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdwarven <hdwarven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:53:41 by hdwarven          #+#    #+#             */
/*   Updated: 2019/02/14 18:13:01 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int					fd;
	static	t_figures	*tetr;
	int					flag;
	char				buff[22];
	int					ret;

	tetr = NULL;
	if (argc == 2)
	{
		fd = check_fd(argv);
		while ((ret = read(fd, buff, 21)) > 0)
		{
			buff[ret] = '\0';
			flag = termin_count(buff);
			if (!check_buff(&tetr, ret, buff))
				do_exit(fd, tetr);
		}
		if (!print_error(flag, tetr))
			do_exit(fd, tetr);
		close(fd);
		solve(tetr);
	}
	else
		fillit_usage(argv[0]);
	return (0);
}

void	do_exit(int fd, t_figures *tetr)
{
	close(fd);
	clear_tetr(tetr);
	exit(0);
}
