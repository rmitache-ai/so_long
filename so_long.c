/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:42:46 by jfritz            #+#    #+#             */
/*   Updated: 2023/08/07 13:50:28 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

void	initialize(t_game *game)
{
	game->map = NULL;
	game->w_map = NULL;
	game->e_c = 0;
	game->p_c = 0;
	game->c_c = 0;
	game->c_found = 0;
	game->e_found = 0;
	game->player.moves = 0;
	game->player.coins = 0;
	game->map = (char **)malloc(sizeof(char *)
			* (game->size_y / SIZE));
	if (game->map == NULL)
		alert("Failed to allocate memory, sir\n");
	game->w_map = (char **)malloc(sizeof(char *)
			* (game->size_y / SIZE));
	if (game->w_map == NULL)
		alert("Failed to allocate memory\n");
}

void	check_parameters(int argc, char	**argv)
{
	char	*ber_found;
	char	*first_dot;
	int		fd;
	char	buffer;

	if (argc != 2)
		alert("Correct Usage: maps/any_map.ber\n");
	fd = open(argv[1], O_RDONLY);
	if (read(fd, &buffer, 1) > 0 && buffer == '\n')
		alert("Newline found at start\n");
	if (fd < 0)
		alert("Failed to load file\n");
	close(fd);
	first_dot = ft_strchr(argv[1], '.');
	ber_found = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
	if (first_dot == NULL)
		alert("Please include .ber in the file name.\n");
	if (ft_strncmp(first_dot, ".ber", 4) == 0 && first_dot[4] == '\0')
		return ;
	else
		alert("Invalid .ber extension\n");
}

int	key_check(int key, t_game *game)
{
	if (key == ESC)
		destroy_win(game);
	else if (key == UP)
		move_up(game);
	else if (key == DOWN)
		move_down(game);
	else if (key == LEFT)
		move_left(game);
	else if (key == RIGHT)
		move_right(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_parameters(argc, argv);
	window_size_calc(&game, argv);
	game.mlx = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx, game.size_x, game.size_y,
			"Wizard in Dungeon: DN Edition");
	initialize(&game);
	calculate_map(&game, argv);
	mlx_hook(game.mlx_window, 2, 0, key_check, (void *)&game);
	mlx_hook(game.mlx_window, 17, 0, destroy_win, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
