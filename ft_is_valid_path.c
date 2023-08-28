/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:27:42 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/28 13:55:10 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_dfs(int x, int y, char *map, t_game *g)
{
	if (map[g->width * y + x] == '1')
		return ;
	if (map[g->width * y + x] != 'V')
	{
		if (map[g->width * y + x] == 'C')
		{
			g->avail_c++;
			map[g->width * y + x] = 'V';
			return ;
		}
		else if (map[g->width * y + x] == 'E')
		{
			g->avail_e++;
			map[g->width * y + x] = 'V';
			return ;
		}
		map[g->width * y + x] = 'V';
		ft_dfs(x + 1, y, map, g);
		ft_dfs(x - 1, y, map, g);
		ft_dfs(x, y + 1, map, g);
		ft_dfs(x, y - 1, map, g);
	}
}

int	ft_is_valid_path(t_game *g)
{
	char	*map;

	map = ft_strdup(g->map_line);
	ft_dfs(g->x, g->y, map, g);
	free(map);
	if (g->c != g->avail_c || g->avail_e != 1)
		return (0);
	return (1);
}
