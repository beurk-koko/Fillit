/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 14:07:58 by pba               #+#    #+#             */
/*   Updated: 2016/02/22 09:37:19 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map			*allocate_t_map(t_dlist *list)
{
	t_map		*map;

	if ((map = (t_map *)malloc(sizeof(t_map))))
	{
		map->res_map = min_square(list->size);
		map->dim = (int)ft_strlen(map->res_map[0]);
		if (!(map->point = (t_point *)malloc(sizeof(t_point))))
			return (NULL);
	}
	return (map);
}

int				main(int ac, char **av)
{
	char		**tetriminos;
	t_map		*map;
	t_dlist		*list;

	if (ac == 2)
	{
		if ((tetriminos = check_file(av[1])))
		{
			list = get_list(tetriminos);
			map = allocate_t_map(list);
			free(tetriminos);
			map->res_map = recursive_check(map, list->head, list);
			display_map(map->res_map);
		}
	}
	else
		error(ac);
	return (0);
}
