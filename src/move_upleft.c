/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_upleft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:34:11 by pba               #+#    #+#             */
/*   Updated: 2016/01/31 05:45:09 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int				get_min_y(char **tetriminos)
{
	int					i;
	int					j;

	i = 0;
	while (tetriminos[i])
	{
		j = 0;
		while (tetriminos[i][j])
		{
			if (tetriminos[i][j] != '.')
				return (i);
			++j;
		}
		++i;
	}
	return (i);
}

static int				get_min_x(char **tetriminos)
{
	int					i;
	int					j;
	int					min_x;

	min_x = 3;
	i = 0;
	while (tetriminos[i])
	{
		j = 0;
		while (tetriminos[i][j])
		{
			if (tetriminos[i][j] != '.')
			{
				if (j < min_x)
					min_x = (j);
			}
			++j;
		}
		++i;
	}
	return (min_x);
}

char					**move_upleft(char **tetriminos)
{
	int					i;
	int					j;
	int					min_y;
	int					min_x;

	min_y = get_min_y(tetriminos);
	min_x = get_min_x(tetriminos);
	i = 0;
	while (tetriminos[i])
	{
		j = 0;
		while (tetriminos[i][j])
		{
			if (tetriminos[i][j] != '.' && (min_x != 0 || min_y != 0))
			{
				tetriminos[i - min_y][j - min_x] = tetriminos[i][j];
				tetriminos[i][j] = '.';
			}
			++j;
		}
		++i;
	}
	return (tetriminos);
}
