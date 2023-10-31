/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:41:37 by rmitache          #+#    #+#             */
/*   Updated: 2023/08/09 12:19:35 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

int	destroy_win(t_game *game)
{
	ft_free_all_allocated_memory(game);
	exit(0);
}

void	window_size_calc(t_game *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		alert("Failed to read the map path. Map even exist?\n");
	}
	data->size_x = count_width(fd) * SIZE;
	data->size_y = count_height(fd) * SIZE;
	close (fd);
}

int	count_width(int fd)
{
	char	buffer[0];
	int		i;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	i = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			i++;
		else
			break ;
	}
	return (i);
}

int	count_height(int fd)
{
	int		linecount;
	char	*bytes;

	linecount = 1;
	bytes = NULL;
	while (1)
	{
		bytes = get_next_line(fd);
		if (bytes)
			linecount++;
		else
			break ;
		free(bytes);
	}
	return (linecount);
}

void	look_for(t_game *game, int y_axis, int local_x)
{
	if ((game->w_map[y_axis][local_x] == 'v')
		|| (game->w_map[y_axis][local_x] == '1')
			|| (game->w_map[y_axis][local_x] == 'X'))
		return ;
	if (game->w_map[y_axis][local_x] == 'C')
		game->c_found++;
	if (game->w_map[y_axis][local_x] == 'E')
		game->e_found++;
	if (game->e_found > 0 && (game->c_found == game->c_c))
		return ;
	game->w_map[y_axis][local_x] = 'v';
	look_for(game, y_axis, local_x + 1);
	look_for(game, y_axis - 1, local_x);
	look_for(game, y_axis, local_x - 1);
	look_for(game, y_axis + 1, local_x);
}
