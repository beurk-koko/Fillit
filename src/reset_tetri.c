/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 23:43:23 by pba               #+#    #+#             */
/*   Updated: 2016/02/19 08:17:30 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int						move_tetri(t_map *map, t_dcell *tetri)
{
	if (tetri->pos->x < map->dim)
	{
		tetri->pos->x += 1;
		map->point->y = tetri->pos->y;
		map->point->x = tetri->pos->x;
		if (check_place(map, tetri) == 1)
			return (1);
	}
	else if (tetri->pos->y < map->dim)
	{
		tetri->pos->x = 0;
		tetri->pos->y += 1;
		map->point->y = tetri->pos->y;
		map->point->x = tetri->pos->x;
		if (check_place(map, tetri) == 1)
			return (1);
	}
	return (0);
}

static void				reset_one_block(t_map *map, t_dcell *tetri,
							t_point *point_t, int offset)
{
	int					i;
	int					j;

	i = tetri->pos->y;
	j = tetri->pos->x;
	if (j == 0)
		offset = 0;
	map->res_map[i + point_t->y][j + point_t->x - offset] = '.';
}

int						replace_tetri(t_map *map, t_dcell *tetri)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < map->dim)
	{
		while (j < map->dim)
		{
			if (move_tetri(map, tetri) == 1)
			{
				write_tetri(map, tetri);
				map->point->x = 0;
				map->point->y = 0;
				return (1);
			}
			++j;
		}
		j = 0;
		++i;
	}
	return (0);
}

int						reset_tetri(t_map *map, t_dcell *tetri)
{
	int				i;

	i = 0;
	if (tetri->put == 0)
		return (0);
	while (i < 4)
	{
		reset_one_block(map, tetri, tetri->point[i], tetri->offset);
		++i;
	}
	tetri->put = 0;
	if (replace_tetri(map, tetri) == 1)
		return (1);
	return (0);
}
