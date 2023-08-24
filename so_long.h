/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:28:54 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/24 19:39:46 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_game
{
	int		width;
	int		height;
	char	*map_line;
	void	*mlx;
	void	*win;
	void	*tree;
	void	*door_o;
	void	*door_x;
	void	*plain;
	void	*cat;
	void	*cat2;
	int		x;
	int		y;
	int		c;
	int		now_c;
}	t_game;

void	ft_error(char *str, int code);

int		ft_is_rect(int fd, t_game *g);
int		ft_map_chk(char **argv, t_game *g);
void	ft_show_map(t_game *g);

char	*ft_dup_noline(char *s1);
char	*ft_join_noline(char *s1, char *s2);
int		ft_strlen_noline(char *line);

void	param_init(t_game *param);
int		key_press(t_game *param, int keycode);

void	ft_set_img(t_game *g);
void	ft_set_img_map(t_game *g, int w, int h);
void	ft_set_map(t_game *g);
void	ft_game_init(t_game *g);

#endif