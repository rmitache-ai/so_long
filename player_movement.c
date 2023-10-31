/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:09:18 by rmitache          #+#    #+#             */
/*   Updated: 2023/08/09 22:25:36 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	legal_moves(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'C')
	{
		game->player.coins++;
		game->map[y][x] = '0';
	}
	else if (game->map[y][x] == 'E')
	{
		if (game->player.coins != game->c_c)
		{
			ft_printf("Pick the remaining coins!\n");
			return (0);
		}
		ft_victory(game);
		return (1);
	}
	return (1);
}

void	move_right(t_game *game)
{
	int		ypos;
	int		xpos;
	int		next_xpos;
	t_image	image;

	image.path = "texture/player/player_right0.xpm";
	image.wlx = *game;
	ypos = game->player.y;
	xpos = game->player.x + SIZE;
/* 	if (game->map[(ypos / SIZE)][(xpos / SIZE)] == 'E'
		&& game->player.coins != game->c_c)
	{
		next_xpos = xpos + SIZE;
		xpos = next_xpos;
	} */
	if (legal_moves(game, (xpos / SIZE), (ypos / SIZE)))
	{
		update(game, xpos, ypos);
		game->player.x = xpos;
		game->player.y = ypos;
		game->player.moves++;
		put_image(image, xpos, ypos);
		ft_printf("Player Moves: %d\n", game->player.moves);
	}
}

void	move_left(t_game *game)
{
	int		ypos;
	int		xpos;
	int		prev_xpos;
	t_image	image;

	image.path = "texture/player/player_right0.xpm";
	image.wlx = *game;
	ypos = game->player.y;
	xpos = game->player.x - SIZE;
/* 	if (game->map[(ypos / SIZE)][(xpos / SIZE)] == 'E'
		&& game->player.coins != game->c_c)
	{
		prev_xpos = xpos - SIZE;
		xpos = prev_xpos;
	} */
	if (legal_moves(game, (xpos / SIZE), (ypos / SIZE)))
	{
		update(game, xpos, ypos);
		game->player.x = xpos;
		game->player.y = ypos;
		put_image(image, xpos, ypos);
		game->player.moves++;
		ft_printf("Player Moves: %d\n", game->player.moves);
	}
}

void	move_up(t_game *game)
{
	int		ypos;
	int		xpos;
	int		prev_ypos;
	t_image	image;

	image.path = "texture/player/player_right0.xpm";
	image.wlx = *game;
	ypos = game->player.y - SIZE;
	xpos = game->player.x;
/* 	if (game->map[(ypos / SIZE)][(xpos / SIZE)] == 'E'
		&& game->player.coins != game->c_c)
	{
		prev_ypos = ypos - SIZE;
		ypos = prev_ypos;
	} */
	if (legal_moves(game, (xpos / SIZE), (ypos / SIZE)))
	{		
		update(game, xpos, ypos);
		game->player.x = xpos;
		game->player.y = ypos;
		put_image(image, xpos, ypos);
		game->player.moves++;
		ft_printf("Player Moves: %d\n", game->player.moves);
	}
}

void	move_down(t_game *game)
{
	int		ypos;
	int		xpos;
	int		next_ypos;
	t_image	image;

	image.path = "texture/player/player_right0.xpm";
	image.wlx = *game;
	ypos = game->player.y + SIZE;
	xpos = game->player.x;
/* 	if (game->map[(ypos / SIZE)][(xpos / SIZE)] == 'E'
		&& game->player.coins != game->c_c)
	{
		next_ypos = ypos + SIZE;
		ypos = next_ypos;
	} */
	if (legal_moves(game, (xpos / SIZE), (ypos / SIZE)))
	{
		update(game, xpos, ypos);
		game->player.x = xpos;
		game->player.y = ypos;
		put_image(image, xpos, ypos);
		game->player.moves++;
		ft_printf("Player Moves: %d\n", game->player.moves);
	}
}
