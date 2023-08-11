/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:28:58 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/11 20:39:35 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str, int code)
{
	perror(str);
	exit(code);
}

int	ft_is_rect(int fd)
{
	char	*line;

	line = get_next_line(fd);
	printf("%s\n", line);
	return (1);
}

int	ft_map_chk(char **argv)
{
	int	fd;

	if (!ft_strnstr(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		ft_error("Map Error", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("File Open Error", 1);
	ft_is_rect(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Arguments Error", 1);
	if (!ft_map_chk(argv))
		ft_error("Map Error", 1);
}
