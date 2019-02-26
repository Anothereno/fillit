/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdwarven <hdwarven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:26:49 by hdwarven          #+#    #+#             */
/*   Updated: 2019/02/14 17:19:37 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct			s_figures
{
	int					fig[64][64];
	char				letter;
	struct s_figures	*next;
	struct s_figures	*head;
}						t_figures;

typedef struct			s_field
{
	int					fig[64][64];
	int					size;
}						t_field;

int						check_buff(t_figures **tetr, int ret, char *buff);
int						print_error(int flag, t_figures *tetr);
size_t					lenght(const char *str);
char					*duplicate(const char *src);
int						sizer(t_figures *head);
void					move_x(t_figures *tetr, int size);
void					move_y(t_figures *tetr, int size);
int						try2move_x(t_figures *tetr, t_field *tab);
int						try2move_y(t_figures *tetr, t_field *tab);
int						min_x(t_figures *tetr, int size);
int						min_y(t_figures *tetr, int size);
void					shift(t_figures *ptr, int y, int x, int size);
void					print_map(int fig[64][64], int size);
int						check_str(char *str, char bukva);
int						check_col(char *str, char bukva);
void					insert2node(int fig[64][64], char *str, char bukva);
t_figures				*take_tail(t_figures **tetr);
void					add2list(t_figures **tetr, char *fig, char bukva);
void					set2default(t_figures *tetr, int size);
int						combinator(t_figures *tetr, t_field *tab);
int						check_size(t_figures *tetr, int size);
int						try2place(t_figures *tetr, t_field *tab);
int						insert2tab(t_figures *tetr, t_field *tab);
int						place2(t_figures *tetr, t_field *tab);
void					solve(t_figures *tetr);
void					clear_prev_map(t_field *tab, char c, int size);
void					clearmap(t_field *tab, int size);
t_field					*create_new_tab(t_figures *tetr);
int						check_hashtag(char *tmp, int i, int num_of_hashtags);
int						get_figure(char *buff, t_figures **tetr);
int						validate(char *buff, int ret);
void					do_x(t_figures *tetr, t_field *tab);
void					do_y(t_figures *tetr, t_field *tab);
void					ft_putstr(char const *s);
void					clear_tetr(t_figures *tetr);
void					do_exit(int fd, t_figures *tetr);
int						termin_count(char *buff);
int						check_fd(char **argv);
void					fillit_usage(char argv[0]);
int						hashcount(char *buff);

#endif
