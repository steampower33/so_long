/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:12:17 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/28 13:15:26 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_a(t_game *g)
{
	if (g->x - 1 <= 0)
		return ;
	if (g->map_line[g->width * g->y + (g->x - 1)] == '1')
		return ;
	if (g->map_line[g->width * g->y + (g->x - 1)] == 'E' && g->c != g->now_c)
		return ;
	else
	{
		if (g->map_line[g->width * g->y + (g->x - 1)] == 'C')
			g->now_c++;
		if (g->map_line[g->width * g->y + (g->x - 1)] == 'E')
			g->now_e++;
		g->map_line[g->width * g->y + g->x] = '0';
		g->x--;
		g->map_line[g->width * g->y + g->x] = 'P';
		g->move_cnt++;
		ft_printf("%d\n", g->move_cnt);
		ft_set_map(g);
	}
}

void	ft_move_s(t_game *g)
{
	if (g->y + 1 >= g->height)
		return ;
	if (g->map_line[g->width * (g->y + 1) + g->x] == '1')
		return ;
	if (g->map_line[g->width * (g->y + 1) + g->x] == 'E' && g->c != g->now_c)
		return ;
	else
	{
		if (g->map_line[g->width * (g->y + 1) + g->x] == 'C')
			g->now_c++;
		if (g->map_line[g->width * (g->y + 1) + g->x] == 'E')
			g->now_e++;
		g->map_line[g->width * g->y + g->x] = '0';
		g->y++;
		g->map_line[g->width * g->y + g->x] = 'P';
		g->move_cnt++;
		ft_printf("%d\n", g->move_cnt);
		ft_set_map(g);
	}
}

void	ft_move_d(t_game *g)
{
	if (g->x + 1 >= g->width)
		return ;
	if (g->map_line[g->width * g->y + (g->x + 1)] == '1')
		return ;
	if (g->map_line[g->width * g->y + (g->x + 1)] == 'E' && g->c != g->now_c)
		return ;
	else
	{
		if (g->map_line[g->width * g->y + (g->x + 1)] == 'C')
			g->now_c++;
		if (g->map_line[g->width * g->y + (g->x + 1)] == 'E')
			g->now_e++;
		g->map_line[g->width * g->y + g->x] = '0';
		g->x++;
		g->map_line[g->width * g->y + g->x] = 'P';
		g->move_cnt++;
		ft_printf("%d\n", g->move_cnt);
		ft_set_map(g);
	}
}

void	ft_move_w(t_game *g)
{
	if (g->y - 1 <= 0)
		return ;
	if (g->map_line[g->width * (g->y - 1) + g->x] == '1')
		return ;
	if (g->map_line[g->width * (g->y - 1) + g->x] == 'E' && g->c != g->now_c)
		return ;
	else
	{
		if (g->map_line[g->width * (g->y - 1) + g->x] == 'C')
			g->now_c++;
		if (g->map_line[g->width * (g->y - 1) + g->x] == 'E')
			g->now_e++;
		g->map_line[g->width * g->y + g->x] = '0';
		g->y--;
		g->map_line[g->width * g->y + g->x] = 'P';
		g->move_cnt++;
		ft_printf("%d\n", g->move_cnt);
		ft_set_map(g);
	}
}

int	ft_move(int keycode, t_game *g)
{
	if (keycode == KEY_A)
		ft_move_a(g);
	else if (keycode == KEY_S)
		ft_move_s(g);
	else if (keycode == KEY_D)
		ft_move_d(g);
	else if (keycode == KEY_W)
		ft_move_w(g);
	else if (keycode == KEY_ESC)
		exit(0);
	if (g->now_e == 1)
	{
		ft_printf("Your move is %d\n", g->move_cnt);
		exit(0);
	}
	return (0);
}
