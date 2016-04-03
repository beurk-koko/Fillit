/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 23:58:56 by pba               #+#    #+#             */
/*   Updated: 2016/02/13 04:28:03 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t			ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	if (str == NULL)
		return (len);
	while (*str++)
		++len;
	return (len);
}
