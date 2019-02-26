# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdwarven <hdwarven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 19:30:32 by hdwarven          #+#    #+#              #
#    Updated: 2019/02/14 18:44:43 by ndremora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

all :	$(NAME)

$(NAME)	:
	gcc -c -Wall -Wextra -Werror *.c -I fillit.h
	gcc *.o -o $(NAME)

clean :
	/bin/rm -f *.o

fclean :	clean
	/bin/rm -f $(NAME)

re :	fclean all
