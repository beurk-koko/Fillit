/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:02:54 by pba               #+#    #+#             */
/*   Updated: 2016/01/31 16:08:06 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_point			*get_one_point(int i, int j)
{
	t_point				*point;

	point = (t_point *)malloc(sizeof(t_point));
	point->y = i;
	point->x = j;
	return (point);
}

t_point					**get_point(char **tetriminos)
{
	int					i;
	int					j;
	int					k;
	t_point				**point;

	if (!(point = (t_point **)malloc(sizeof(t_point *) * 5)))
		return (NULL);
	point[4] = NULL;
	k = 0;
	i = 0;
	while (tetriminos[i])
	{
		j = 0;
		while (tetriminos[i][j])
		{
			if (tetriminos[i][j] != '.')
				point[k++] = get_one_point(i, j);
			j++;
		}
		i++;
	}
	return (point);
}
