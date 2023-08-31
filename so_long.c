/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:28:58 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/31 15:55:08 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_init(t_game *g)
{
	g->now_c = 0;
	g->now_e = 0;
	g->move_cnt = 0;
	g->mlx = mlx_init();
	ft_set_img(g);
	g->win = mlx_new_window(g->mlx, g->width * 32, g->height * 32, "so_long");
	ft_set_map(g);
}

int	ft_exit(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	*g;

	g = (t_game *)malloc(sizeof(t_game));
	if (!g)
		ft_error("Malloc Error\n");
	if (argc != 2)
		ft_error("Arguments Error\n");
	if (!ft_map_chk(argv, g))
		ft_error("Map Error\n");
	ft_game_init(g);
	mlx_hook(g->win, KEY_PRESS, 0, &ft_move, g);
	mlx_hook(g->win, KEY_EXPOSE, 0, &ft_exit, g);
	mlx_loop(g->mlx);
	return (0);
}
