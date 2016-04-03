/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:01:11 by pba               #+#    #+#             */
/*   Updated: 2016/02/14 22:55:04 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_one_place(t_map *map, t_point *point_t, int offset)
{
	int			y;
	int			x;

	y = map->point->y;
	x = map->point->x;
	if (x == 0)
		offset = 0;
	if (y + point_t->y < map->dim
			&& x + point_t->x - offset < map->dim
			&& map->res_map[y + point_t->y][x + point_t->x - offset] == '.')
		return (1);
	return (0);
}

int				check_place(t_map *map, t_dcell *tetri)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (check_one_place(map, tetri->point[i], tetri->offset) == 0)
			return (0);
		++i;
	}
	return (1);
}
