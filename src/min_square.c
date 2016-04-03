/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:44:32 by pba               #+#    #+#             */
/*   Updated: 2016/02/14 23:06:33 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char				**min_square(int tetri_nb)
{
	char			**res_map;
	int				dim;
	int				i;

	dim = ft_sqrt(tetri_nb) * 2;
	res_map = make_map(dim);
	i = 0;
	while (i < dim)
	{
		write_point(res_map[i], dim);
		++i;
	}
	return (res_map);
}
