/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:50 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/25 18:07:06 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_rect(int fd, t_game *g)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_error("map is empty", 1);
	g->width = ft_strlen(line) - 1;
	g->height = 0;
	g->map_line = ft_dup_noline(line);
	while (line)
	{
		line = get_next_line(fd);
		g->height++;
		if (line)
		{
			if (g->width != ft_strlen_noline(line))
				return (0);
			g->map_line = ft_join_noline(g->map_line, line);
		}
	}
	return (1);
}

int	ft_is_closed(t_game *g)
{
	int	idx;
	int	line_len;

	line_len = ft_strlen(g->map_line);
	idx = 0;
	while (idx < line_len)
	{
		if (idx < g->width && g->map_line[idx] != '1')
			return (0);
		else if (idx % g->width == 0 && g->map_line[idx] != '1')
			return (0);
		else if (idx >= g->width - 1 && (idx - (g->width - 1)) % g->width == 0
			&& g->map_line[idx] != '1')
			return (0);
		else if ((line_len - g->width <= idx && idx < line_len)
			&& g->map_line[idx] != '1')
			return (0);
		idx++;
	}
	return (1);
}

int	ft_is_composed(t_game *g)
{
	int	idx;
	int	line_len;

	g->c = 0;
	g->e = 0;
	g->p = 0;
	line_len = ft_strlen(g->map_line);
	idx = 0;
	while (idx < line_len)
	{
		if (g->map_line[idx] == 'C')
			g->c++;
		if (g->map_line[idx] == 'E')
			g->e++;
		if (g->map_line[idx] == 'P')
			g->p++;
		if (g->e >= 2 || g->p >= 2)
			return (0);
		idx++;
	}
	return (1);
}

int	ft_map_chk(char **argv, t_game *g)
{
	int	fd;

	if (!ft_strnstr(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		ft_error("Map Error", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("File Open Error", 1);
	if (!ft_is_rect(fd, g))
		ft_error("Map is not rectangular", 1);
	if (!ft_is_closed(g))
		ft_error("Map is not closed by 1", 1);
	if (!ft_is_composed(g))
		ft_error("Characters is not enough", 1);
	close(fd);
	return (1);
}
