/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:48:32 by pba               #+#    #+#             */
/*   Updated: 2016/02/13 04:17:46 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			retrieve_letter(char **tetri)
{
	if (tetri[0][0] != '.')
		return (tetri[0][0]);
	else if (tetri[0][1] != '.')
		return (tetri[0][1]);
	else
		return (tetri[1][0]);
}

static void			write_one_block(t_map *map,
					t_point *point_t, int offset, char letter)
{
	int				i;
	int				j;

	if (map->point->x == 0)
		offset = 0;
	i = map->point->y;
	j = map->point->x;
	map->res_map[i + point_t->y][j + point_t->x - offset] = letter;
}

void				write_tetri(t_map *map, t_dcell *tetri)
{
	int				i;
	char			letter;

	letter = retrieve_letter(tetri->tetri);
	i = 0;
	while (tetri->point[i])
	{
		write_one_block(map, tetri->point[i], tetri->offset, letter);
		++i;
	}
	tetri->put = 1;
	tetri->pos->y = map->point->y;
	tetri->pos->x = map->point->x;
}
