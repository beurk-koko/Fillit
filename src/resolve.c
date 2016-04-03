/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 23:04:15 by pba               #+#    #+#             */
/*   Updated: 2016/02/19 08:18:24 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_map			*reset(t_dlist *list, t_map *map)
{
	t_dcell				*tmp;
	int					i;

	tmp = list->head;
	while (tmp->next != list->head)
	{
		tmp->put = 0;
		tmp = tmp->next;
	}
	tmp->put = 0;
	map->dim = (int)ft_strlen(map->res_map[0]) + 1;
	free(map->res_map);
	map->res_map = NULL;
	map->res_map = make_map(map->dim);
	i = 0;
	while (i < map->dim)
	{
		write_point(map->res_map[i], map->dim);
		++i;
	}
	return (map);
}

static int				check_put(t_dlist *list)
{
	t_dcell				*tmp;

	tmp = list->head;
	while (tmp->next != list->head)
	{
		if (tmp->put == 0)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->put == 0)
		return (0);
	return (1);
}

t_dcell					*previous_tetri(t_map *map, t_dcell *tetri,
							t_dlist *list)
{
	map->point->x = 0;
	while (map->point->x < map->dim && check_put(list) != 1)
	{
		if (put_in(map, tetri) == 1)
		{
			tetri = tetri->next;
				map->point->x = 0;
				map->point->y = 0;
		}
		map->point->x++;
	}
	return (tetri);
}

char					**recursive_check(t_map *map,
							t_dcell *tetri, t_dlist *list)
{
	map->point->y = 0;
	while (map->point->y <= map->dim)
	{
		if (map->point->y == map->dim)
		{
			if (check_put(list) == 1)
				return (map->res_map);
			return (recursive_check(reset(list, map), list->head, list));
		}
		tetri = previous_tetri(map, tetri, list);
		if (map->point->y == (map->dim - 1) && check_put(list) != 1)
		{
			while (reset_tetri(map, tetri->prev) != 1)
			{
				if (tetri->prev == list->head)
					break ;
				tetri = tetri->prev;
			}
			if (tetri->prev == list->head && reset_tetri(map, tetri->prev) != 1)
				return (recursive_check(reset(list, map), list->head, list));
		}
		else
			map->point->y++;
	}
	return (map->res_map);
}
