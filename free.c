/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:40:40 by rmitache          #+#    #+#             */
/*   Updated: 2023/08/09 12:17:43 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game_map(char *msg, t_game *game, int y_axis)
{
	int	i;

	ft_printf("Error\n");
	ft_printf("%s", msg);
	i = 0;
	while (i < y_axis)
	{
		free(game->map[i]);
		free(game->w_map[i]);
		i++;
	}
	free(game->map);
	free(game->w_map);
	mlx_destroy_window(game->mlx, game->mlx_window);
	exit(1);
}

void	ft_victory(t_game *game)
{
	ft_free_all_allocated_memory(game);
	ft_printf(GREEN"\n\
██████████████████████████████████████████████████████████████████\n\
██                                                              ██\n\
██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
██                                                              ██\n\
██████████████████████████████████████████████████████████████████\n\n\
"RESET);
	exit (0);
}

void	ft_free_all_allocated_memory(t_game *game)
{
	ft_free_map(game);
	mlx_destroy_window(game->mlx, game->mlx_window);
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->size_y / SIZE)
	{
		free(game->map[i]);
		game->map[i] = NULL;
		free(game->w_map[i]);
		game->w_map[i] = NULL;
		i++;
	}
	free(game->map);
	free(game->w_map);
}

void	alert(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s", msg);
	exit (1);
}
