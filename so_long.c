/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:28:58 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/26 19:53:36 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_img(t_game *g)
{
	int	w;
	int	h;

	g->tree = mlx_xpm_file_to_image(g->mlx, "./textures/tree.xpm", &w, &h);
	g->door_o = mlx_xpm_file_to_image(g->mlx, "./textures/door_o.xpm", &w, &h);
	g->door_x = mlx_xpm_file_to_image(g->mlx, "./textures/door_x.xpm", &w, &h);
	g->plain = mlx_xpm_file_to_image(g->mlx, "./textures/plain.xpm", &w, &h);
	g->cat = mlx_xpm_file_to_image(g->mlx, "./textures/cat.xpm", &w, &h);
	g->cat2 = mlx_xpm_file_to_image(g->mlx, "./textures/cat2.xpm", &w, &h);
}

void	ft_set_img_map(t_game *g, int w, int h)
{
	mlx_put_image_to_window(g->mlx, g->win, g->plain, w * 32, h * 32);
	if (g->map_line[h * g->width + w] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->tree, w * 32, h * 32);
	else if (g->map_line[h * g->width + w] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->cat2, w * 32, h * 32);
	else if (g->map_line[h * g->width + w] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->cat, w * 32, h * 32);
	else if (g->map_line[h * g->width + w] == 'E' && (g->c == g->now_c))
		mlx_put_image_to_window(g->mlx, g->win, g->door_o, w * 32, h * 32);
	else if (g->map_line[h * g->width + w] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->door_x, w * 32, h * 32);
}

void	ft_set_map(t_game *g)
{
	int	w;
	int	h;

	h = 0;
	while (h < g->height)
	{
		w = 0;
		while (w < g->width)
		{
			ft_set_img_map(g, w, h);
			w++;
		}
		h++;
	}
}

void	ft_game_init(t_game *g)
{
	g->now_c = 0;
	g->move_cnt = 0;
	g->now_e = 0;
	g->mlx = mlx_init();
	ft_set_img(g);
	g->win = mlx_new_window(g->mlx, g->width * 32, g->height * 32, "so_long");
	ft_set_map(g);
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
	ft_game_init(g);
	mlx_hook(g->win, X_EVENT_KEY_RELEASE, 0, &ft_move, g);
	mlx_loop(g->mlx);
	return (0);
}
