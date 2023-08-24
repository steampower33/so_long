/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:35:21 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/24 20:01:06 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode)
{
	if (keycode == KEY_W)
		printf("W\n");
	else if (keycode == KEY_S)
		printf("S\n");
	else if (keycode == KEY_A)
		printf("A\n");
	else if (keycode == KEY_D)
		printf("D\n");
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
