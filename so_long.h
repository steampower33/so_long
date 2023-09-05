/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:28:54 by seunlee2          #+#    #+#             */
/*   Updated: 2023/09/05 09:43:11 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "./printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>

# define KEY_PRESS		2
# define KEY_EXPOSE		17

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
	int		map_len;
	void	*mlx;
	void	*win;
	void	*tree;
	void	*door_o;
	void	*door_x;
	void	*plain;
	void	*cat;
	void	*cat2;
	int		c;
	int		now_c;
	int		avail_c;
	int		e;
	int		now_e;
	int		avail_e;
	int		p;
	int		x;
	int		y;
	int		move_cnt;
}	t_game;

void	ft_error(char *str);

void	ft_dfs(int x, int y, char *map, t_game *g);
int		ft_is_valid_path(t_game *g);

int		ft_is_rect(int fd, t_game *g);
int		ft_is_closed(t_game *g);
int		ft_is_composed(t_game *g);
int		ft_map_chk(char **argv, t_game *g);

char	*ft_dup_noline(char *s1);
char	*ft_join_noline(char *s1, char *s2);
int		ft_strlen_noline(char *line);
int		ft_len(char	*line);

void	ft_set_img(t_game *g);
void	ft_set_img_map(t_game *g, int w, int h);
void	ft_set_map(t_game *g);

void	ft_game_init(t_game *g);
int		ft_exit(t_game *g);

void	ft_move_a(t_game *g);
void	ft_move_s(t_game *g);
void	ft_move_d(t_game *g);
void	ft_move_w(t_game *g);
int		ft_move(int keycode, t_game *g);

#endif