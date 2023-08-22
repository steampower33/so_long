/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:28:58 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/22 20:11:51 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str, int code)
{
	perror(str);
	exit(code);
}

int	ft_is_rect(int fd, t_game *g)
{
	char	*line;

	line = get_next_line(fd);
	g->width = ft_strlen(line);
	g->map_line = ft_strdup(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		ft_strlen(line);
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
	ft_is_rect(fd, g);
	close(fd);
	return (1);
}

void	ft_show_map(char *map, t_game *g)
{
	int		fd;

	if (!ft_strnstr(map + ft_strlen(map) - 4, ".ber", 4))
		ft_error("Map Error", 1);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error("File Open Error", 1);
}

int	main(int argc, char **argv)
{
	t_game	*g;

	g = (t_game *)malloc(sizeof(t_game));
	if (!g)
		ft_error("Malloc Error", 1);
	if (argc != 2)
		ft_error("Arguments Error", 1);
	if (!ft_map_chk(argv, g))
		ft_error("Map Error", 1);
	// ft_show_map(argv[1], g);
}
