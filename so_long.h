/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:20:47 by rmitache          #+#    #+#             */
/*   Updated: 2023/08/07 14:35:52 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>

# define ESC	53
# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define SIZE	31
# define GREEN "\033[32m"
# define RESET "\033[0m"

typedef struct s_player
{
	int	x;
	int	y;
	int	coins;
	int	moves;
}			t_player;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_window;
	char		**map;
	char		**w_map;
	int			size_x;
	int			size_y;
	t_player	player;
	int			c_found;
	int			e_found;
	int			e_c;
	int			p_c;
	int			c_c;

}				t_game;

typedef struct s_image
{
	void			*img;
	char			*path;
	struct s_game	wlx;
	int				img_height;
	int				img_width;
	int				x;
	int				y;
}			t_image;

void	move_right(t_game *game);
int		key_check(int key, t_game *game);
void	move_left(t_game *game);
void	move_up(t_game	*game);
void	move_down(t_game	*game);
void	*put_image(t_image image, int x, int y);
void	update(t_game *game, int x, int y);
void	window_size_calc(t_game *data, char **argv);
int		destroy_win(t_game *game);
int		count_width(int fd);
int		count_height(int fd);
void	calculate_map(t_game *game, char **argv);
void	map_lenght(char *area, t_game *game, int y_axis);
void	free_game_map(char *msg, t_game *game, int y_axis);
void	alert(char *msg);
void	fill_area(t_game *game, int y_axis);
void	add_sprite(t_game *game, int x, int y);
void	check_map(char	*area, t_game *game, int y_axis);
void	check_walls(char *area, t_game *game, int y_axis);
int		check_char(const char *str, t_game *game, int y_axis);
void	check_path(t_game *game, int y_axis);
void	look_for(t_game *game, int y_axis, int local_x);
void	ft_free_all_allocated_memory(t_game *game);
void	ft_free_map(t_game *game);
void	ft_victory(t_game *game);
void	check_parameters(int argc, char	**argv);

#endif