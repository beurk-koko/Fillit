/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:22:55 by pba               #+#    #+#             */
/*   Updated: 2016/02/14 18:12:49 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_dlist			*get_list(char **tetriminos)
{
	t_dlist		*list;
	char		**tetri;
	t_point		**point;
	int			i;

	i = 0;
	list = dlist_new();
	while (tetriminos[i])
	{
		tetri = NULL;
		tetri = move_upleft(get_tab(tetriminos[i]));
		point = get_point(tetri);
		list = dlist_append(list, tetri, point);
		i++;
	}
	return (list);
}
