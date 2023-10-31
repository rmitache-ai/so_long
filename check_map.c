/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:51:17 by rmitache          #+#    #+#             */
/*   Updated: 2023/08/10 15:17:01 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_char(const char *str, t_game *game, int y_axis)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == '\n' || str[i] == 'C'
			|| str[i] == 'P' || str[i] == 'E')
			i++;
		else
		{
			free_game_map("Random Char found\n", game, y_axis);
			return (0);
		}
	}
	return (1);
}

void	check_walls(char *area, t_game *game, int y_axis)
{
	int	i;

	if (ft_strlen(game->map[0]) != ft_strlen(game->map[y_axis]))
		free_game_map("Map is not rectangle!\n", game, y_axis);
	if (ft_strlen(area) == 1)
		free_game_map("One Character?\n", game, y_axis);
	if (y_axis == 0)
	{
		i = 0;
		while (area[i] != '\0')
		{
			if (area[i] != '1' && area[i] != '\n')
				free_game_map("Invalid roof map\n", game, y_axis);
			i++;
		}
	}
	if (game->map[y_axis][0] != '1' || game->map[y_axis][i - 1] != '1')
		free_game_map("Invalid walls\n", game, y_axis);
}

void	check_entities(char *area, t_game *game, int y_axis)
{
	while (*area && *area != '\n' && check_char(area, game, y_axis))
	{
		if (*area == 'E')
			game->e_c++;
		if (*area == 'P')
			game->p_c++;
		if (*area == 'C')
			game->c_c++;
		area++;
	}
	if ((y_axis + 1) == (game->size_y / SIZE))
	{
		if (game->e_c != 1)
			free_game_map("E should be 1\n", game, y_axis);
		if (game->c_c <= 0)
			free_game_map("No coins found\n", game, y_axis);
		if (game->p_c != 1)
			free_game_map("P should be 1\n", game, y_axis);
	}
}

void	check_path(t_game *game, int y_axis)
{
	int	local_y_axis;
	int	local_x_axis;

	local_y_axis = (game->player.y / SIZE);
	local_x_axis = (game->player.x / SIZE);
	if ((y_axis + 1) == (game->size_y / SIZE))
	{
		look_for(game, local_y_axis, local_x_axis);
		if ((game->e_found == 0) || (game->c_found != game->c_c))
			free_game_map("No valid path\n", game, y_axis);
	}
}

void	check_map(char *area, t_game *game, int y_axis)
{
	check_walls(area, game, y_axis);
	check_entities(area, game, y_axis);
	check_path(game, y_axis);
}
