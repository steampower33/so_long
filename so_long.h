/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:28:54 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/24 15:25:33 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_game
{
	int		width;
	int		height;
	char	*map_line;
}	t_game;

void	ft_error(char *str, int code);
void	ft_show_map(char *map);

char	*ft_dup_noline(const char *s1);
char	*ft_join_noline(char const *s1, char const *s2);
#endif