/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2dimtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 19:48:06 by pba               #+#    #+#             */
/*   Updated: 2016/01/27 01:47:29 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			*get_line(char *tetriminos)
{
	int				i;

	i = 0;
	while (tetriminos[i])
	{
		if (tetriminos[i] == '\n')
			tetriminos[i] = '\0';
		++i;
	}
	return (tetriminos);
}

char				**get_tab(char *tetriminos)
{
	int				i;
	char			**tetri;

	if ((tetri = (char **)malloc(sizeof(char *) * 5)))
	{
		tetri[4] = NULL;
		i = 0;
		while (i < 4)
		{
			tetri[i] = ft_strdup(get_line(tetriminos));
			tetriminos += 5;
			++i;
		}
	}
	return (tetri);
}
