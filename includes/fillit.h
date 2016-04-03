/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 14:03:27 by pba               #+#    #+#             */
/*   Updated: 2016/02/22 09:35:49 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

# define BUF_SIZE		19

typedef struct			s_point
{
	int					y;
	int					x;
}						t_point;
typedef struct			s_dcell
{
	t_point				**point;
	t_point				*pos;
	char				**tetri;
	int					put;
	int					offset;
	struct s_dcell		*prev;
	struct s_dcell		*next;
}						t_dcell;
typedef struct			s_dlist
{
	int					size;
	struct s_dcell		*head;
}						t_dlist;
typedef struct			s_map
{
	char				**res_map;
	int					dim;
	t_point				*point;
}						t_map;
char					**check_file(char *file);
int						check_around(char *str, int i, char c);
char					**get_tab(char *tetriminos);
char					**move_upleft(char **tetriminos);
t_point					**get_point(char **tetriminos);
char					**min_square(int tetri_nb);
int						check_place(t_map *map, t_dcell *tetri);
void					write_tetri(t_map *map, t_dcell *tetri);
int						reset_tetri(t_map *map, t_dcell *tetri);
int						move_tetri(t_map *map, t_dcell *tetri);
void					write_point(char *line, int dim);
char					**recursive_check(t_map *map,
							t_dcell *tetri, t_dlist *list);
int						put_in(t_map *map, t_dcell *tetri);
void					put_out(t_map *map, t_dcell *tetri);
t_dcell					*dcell_new(char **tetri, t_point **point);
t_dlist					*dlist_new();
t_dlist					*dlist_append(t_dlist *list, char **tetri,
							t_point **point);
t_dlist					*get_list(char **tetriminos);
void					reset_list(t_dlist *list);
void					error(int ac);

#endif
