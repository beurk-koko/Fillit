/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 02:35:28 by pba               #+#    #+#             */
/*   Updated: 2016/02/15 01:27:08 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_dcell				*dcell_new(char **tetri, t_point **point)
{
	t_dcell			*cell;

	if ((cell = (t_dcell *)malloc(sizeof(t_dcell))))
	{
		cell->point = point;
		cell->tetri = tetri;
		cell->prev = NULL;
		cell->next = NULL;
	}
	return (cell);
}

t_dlist				*dlist_new(void)
{
	t_dlist			*list;

	if ((list = (t_dlist *)malloc(sizeof(t_dlist))))
	{
		list->size = 0;
		list->head = NULL;
	}
	return (list);
}

static int			define_offset(t_point *point)
{
	if (point->x > 0)
		return (point->x);
	return (0);
}

t_dlist				*dlist_append(t_dlist *list, char **tetri, t_point **point)
{
	t_dcell			*newcell;

	newcell = dcell_new(tetri, point);
	if (list && newcell)
	{
		if (!(newcell->pos = (t_point *)malloc(sizeof(t_point))))
			return (NULL);
		if (list->head == NULL)
		{
			list->head = newcell;
			newcell->prev = list->head;
			newcell->next = list->head;
		}
		else
		{
			newcell->next = list->head;
			newcell->prev = list->head->prev;
			list->head->prev->next = newcell;
			list->head->prev = newcell;
		}
		newcell->put = 0;
		newcell->offset = define_offset(newcell->point[0]);
		++list->size;
	}
	return (list);
}
