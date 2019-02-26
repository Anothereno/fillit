/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:20:56 by ndremora          #+#    #+#             */
/*   Updated: 2019/02/14 17:25:10 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_fd(char **argv)
{
	int fd;

	if ((fd = open(argv[1], O_RDONLY)) == -1 || read(fd, NULL, 0) < 0)
	{
		write(1, "error", 6);
		exit(0);
	}
	return (fd);
}

int		check_buff(t_figures **tetr, int ret, char *buff)
{
	static int count;

	count++;
	if (!validate(buff, ret) || count > 26)
	{
		write(1, "error\n", 6);
		return (0);
	}
	get_figure(buff, tetr);
	return (1);
}
