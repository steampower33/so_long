/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:35:21 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/25 16:32:15 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (0);
}
