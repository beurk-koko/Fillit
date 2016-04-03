/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 16:10:38 by pba               #+#    #+#             */
/*   Updated: 2016/01/31 05:54:22 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

dlist		*dlist_append(dlist *list, void *newdata)
{
	dcell		*newcell;

	if (list)
	{
		if ((newcell = (dcell*)malloc(sizeof(dcell))))
		{
			newcell->data = newdata;
			if (list->head == NULL)
			{
				list->head = newcell;
				newcell->prev = list->head;
				newcell->next = list->head;
			}
			else
			{
				newcell->next = list->head;
				list->head->prev->next = newcell;
				list->head->prev = newcell;
			}
			list->len++;
		}
	}
	return (list);
}
