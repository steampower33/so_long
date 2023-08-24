/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:35:21 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/24 18:26:06 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	param_init(t_game *g)
{
	g->x = 3;
	g->y = 4;
}

int	key_press(t_game *g, int keycode)
{
	if (keycode == KEY_W)
		g->y++;
	else if (keycode == KEY_S)
		g->y--;
	else if (keycode == KEY_A)
		g->x--;
	else if (keycode == KEY_D)
		g->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
