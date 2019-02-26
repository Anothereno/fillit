/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdwarven <hdwarven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 19:01:32 by hdwarven          #+#    #+#             */
/*   Updated: 2019/02/14 17:28:17 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_hashtag(char *tmp, int i, int num_of_hashtags)
{
	if (!num_of_hashtags)
		num_of_hashtags = 0;
	if (tmp[i + 1] == '#')
		num_of_hashtags++;
	if (tmp[i - 1] == '#')
		num_of_hashtags++;
	if (tmp[i + 5] == '#')
		num_of_hashtags++;
	if (tmp[i - 5] == '#')
		num_of_hashtags++;
	return (num_of_hashtags);
}

int			validate(char *buff, int ret)
{
	int num_of_hashtags;
	int i;

	i = 0;
	num_of_hashtags = 0;
	while (buff[i] == 10 || buff[i] == 46 || buff[i] == 35)
	{
		if (buff[i] == '\n')
		{
			if (i == 20)
				buff[i] = '\0';
			if (i != 4 && i != 9 && i != 14 && i != 19 && i != 20)
				return (0);
		}
		if (buff[i] == '#')
			num_of_hashtags = check_hashtag(buff, i, num_of_hashtags);
		i++;
	}
	if ((num_of_hashtags != 6 && num_of_hashtags != 8) || i != ret)
		return (0);
	if (!hashcount(buff) || buff[4] != '\n' || buff[9] != '\n'
		|| buff[14] != '\n' || buff[19] != '\n')
		return (0);
	return (1);
}

int			hashcount(char *buff)
{
	char	*str;
	int		count;

	count = 0;
	str = buff;
	while (*str)
	{
		if (*str == '#')
			count++;
		str++;
	}
	if (count != 4)
		return (0);
	return (1);
}

int			termin_count(char *buff)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = buff;
	if (ptr)
		while (*ptr)
		{
			if (*ptr == '\n')
				i++;
			ptr++;
		}
	return (i - 4);
}
