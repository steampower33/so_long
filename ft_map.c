/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:50 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/28 14:00:20 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_rect(int fd, t_game *g)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_error("map is empty\n");
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

	g->map_len = ft_strlen(g->map_line);
	idx = 0;
	while (idx < g->map_len)
	{
		if (idx < g->width && g->map_line[idx] != '1')
			return (0);
		else if (idx % g->width == 0 && g->map_line[idx] != '1')
			return (0);
		else if (idx >= g->width - 1 && (idx - (g->width - 1)) % g->width == 0
			&& g->map_line[idx] != '1')
			return (0);
		else if ((g->map_len - g->width <= idx && idx < g->map_len)
			&& g->map_line[idx] != '1')
			return (0);
		idx++;
	}
	return (1);
}

int	ft_is_composed(t_game *g)
{
	int	idx;

	g->c = 0;
	g->e = 0;
	g->p = 0;
	idx = 0;
	while (idx < g->map_len)
	{
		if (g->map_line[idx] == 'C')
			g->c++;
		if (g->map_line[idx] == 'E')
			g->e++;
		if (g->map_line[idx] == 'P')
		{
			g->p++;
			g->x = idx % g->width;
			g->y = idx / g->width;
		}
		if (g->e >= 2 || g->p >= 2)
			return (0);
		idx++;
	}
	return (1);
}

int	ft_map_chk(char **argv, t_game *g)
{
	int	fd;

	g->avail_c = 0;
	g->avail_e = 0;
	if (!ft_strnstr(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		ft_error("Map Error\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("File Open Error\n");
	if (!ft_is_rect(fd, g))
		ft_error("Map is not rectangular\n");
	close(fd);
	if (!ft_is_closed(g))
		ft_error("Map is not closed by 1\n");
	if (!ft_is_composed(g))
		ft_error("Characters is not enough\n");
	if (!ft_is_valid_path(g))
		ft_error("Map has not valid path\n");
	return (1);
}
