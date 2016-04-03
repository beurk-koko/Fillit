/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 18:40:19 by pba               #+#    #+#             */
/*   Updated: 2016/02/21 09:47:33 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			check_line_size(int fd)
{
	char			*line;
	int				count;
	int				blocks;
	int				i;

	i = 1;
	count = 0;
	blocks = 0;
	while (get_next_line(fd, &line))
	{
		if (i != 5 && ft_strlen(line) != 4)
			return (0);
		blocks += ft_countchar(line, '#');
		if (i == 5)
		{
			if (ft_strcmp(line, "") != 0 || blocks != 4)
				return (0);
			blocks = 0;
			i = 0;
			++count;
		}
		++i;
	}
	close(fd);
	return ((i == 5 && blocks == 4) ? ++count : 0);
}

static char			**get_tetriminos(char *file, int count)
{
	char			**tetriminos;
	char			buf[BUF_SIZE + 1];
	int				ret;
	int				fd;
	int				i;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	if ((tetriminos = (char **)malloc(sizeof(char *) * (count + 1))))
	{
		tetriminos[count] = NULL;
		i = 0;
		while ((ret = read(fd, buf, BUF_SIZE + 2)))
		{
			buf[BUF_SIZE] = '\0';
			tetriminos[i] = ft_strdup(buf);
			i++;
		}
	}
	close(fd);
	return (tetriminos);
}

static int			check_char(char **tetriminos)
{
	int				i;
	int				j;

	j = 0;
	while (tetriminos[j])
	{
		i = 0;
		while (tetriminos[j][i])
		{
			if (tetriminos[j][i] != '.'
				&& tetriminos[j][i] != '#' && tetriminos[j][i] != '\n')
				return (0);
			++i;
		}
		++j;
	}
	return (1);
}

static int			check_map(char **tetriminos, char c)
{
	int				i;
	int				j;
	int				blocks;

	j = 0;
	while (tetriminos[j])
	{
		blocks = 0;
		i = 0;
		while (tetriminos[j][i])
		{
			if (tetriminos[j][i] == '#')
			{
				tetriminos[j][i] = c;
				blocks += check_around(tetriminos[j], i, '#');
			}
			++i;
		}
		if (blocks < 3 || c > 90)
			return (0);
		++j;
		++c;
	}
	return (1);
}

char				**check_file(char *file)
{
	int				fd;
	int				count;
	char			**tetriminos;

	tetriminos = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	if ((count = check_line_size(fd)))
	{
		tetriminos = get_tetriminos(file, count);
		if ((check_char(tetriminos)) && (check_map(tetriminos, 'A')))
			return (tetriminos);
	}
	ft_putstr_fd("error\n", 2);
	return (NULL);
}
