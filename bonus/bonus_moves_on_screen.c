/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_moves_on_screen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:18:44 by rmitache          #+#    #+#             */
/*   Updated: 2023/08/09 21:00:02 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	show_moves(t_game *game)
{
	char	*moves;
	t_image	bg_img;

	bg_img.path = "texture/tiles/wall.xpm";
	bg_img.wlx = *game;
	put_image(bg_img, 0, 0);
	moves = ft_itoa(game->player.moves);
	mlx_string_put(game->mlx, game->mlx_window, 10, 20, 0x00FF66, moves);
	free(moves);
}

void	alert(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s", msg);
	exit (1);
}
