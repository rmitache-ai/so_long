/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:29:28 by rmitache          #+#    #+#             */
/*   Updated: 2023/08/05 15:51:50 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_area(t_game *game, int y_axis)
{
	int			x_axis;
	t_image		img;

	img.wlx = *game;
	x_axis = 0;
	while (game->map[y_axis][x_axis])
	{
		if (game->map[y_axis][x_axis] == '1')
			img.path = "texture/tiles/wall.xpm";
		else if (game->map[y_axis][x_axis] == '0')
			img.path = "texture/tiles/floor.xpm";
		else if (game->map[y_axis][x_axis] == 'E')
			img.path = "texture/tiles/exit_closed.xpm";
		else if (game->map[y_axis][x_axis] == 'C')
			img.path = "texture/tiles/coins.xpm";
		else if (game->map[y_axis][x_axis] == 'P')
		{
			game->player.y = SIZE * y_axis;
			game->player.x = SIZE * x_axis;
			img.path = "texture/player/player_right0.xpm";
		}
		put_image(img, (SIZE * x_axis), (SIZE * y_axis));
		x_axis++;
	}
}

void	map_lenght(char *area, t_game *game, int y_axis)
{
	int		x_axis;

	x_axis = 0;
	game->map[y_axis] = ft_calloc(1, ft_strlen(area) + 1);
	if (game->map[y_axis] == NULL)
		free_game_map("Failed to alocate axis.\n", game, y_axis);
	while (area[x_axis])
	{
		if (area[x_axis] == '\n' || area[x_axis] == '\0')
			break ;
		game->map[y_axis][x_axis] = area[x_axis];
		x_axis++;
	}
	fill_area(game, y_axis);
	check_map(area, game, y_axis);
}

void	map_copy(char *area, t_game *game, int y_axis)
{
	int		x_axis;

	x_axis = 0;
	game->w_map[y_axis] = ft_calloc(1, ft_strlen(area) + 1);
	if (game->w_map[y_axis] == NULL)
		free_game_map("Failed to alocate axis copy.\n", game, y_axis);
	while (area[x_axis])
	{
		if (area[x_axis] == '\n' || area[x_axis] == '\0')
			break ;
		game->w_map[y_axis][x_axis] = area[x_axis];
		x_axis++;
	}
}

void	calculate_map(t_game *game, char **argv)
{
	int		y_axis;
	char	*area;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 1)
	{
		close (fd);
		free_game_map("FD Failed\n", game, 0);
	}
	y_axis = 0;
	while (y_axis < game->size_y / SIZE)
	{
		area = get_next_line(fd);
		if (!area || ft_strncmp(area, "\n", 1) == 0)
			free_game_map("Empty map or newline found\n", game, y_axis);
		map_copy(area, game, y_axis);
		map_lenght(area, game, y_axis);
		free(area);
		y_axis++;
	}
	close(fd);
}
