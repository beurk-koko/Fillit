/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_green_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 23:44:40 by pba               #+#    #+#             */
/*   Updated: 2016/02/22 10:08:32 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_green_fd(char const *str, int fd)
{
	ft_putstr_fd("\033[1;92m", fd);
	while (*str)
		ft_putchar_fd(*str++, fd);
	ft_putstr_fd("\033[0m", fd);
}
