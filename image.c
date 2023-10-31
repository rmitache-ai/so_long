/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:08:14 by rmitache          #+#    #+#             */
/*   Updated: 2023/08/05 15:45:59 by rmitache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*put_image(t_image image, int x, int y)
{
	image.img = mlx_xpm_file_to_image(image.wlx.mlx, image.path,
			&image.img_width, &image.img_height);
	mlx_put_image_to_window(image.wlx.mlx, image.wlx.mlx_window,
		image.img, x, y);
	mlx_destroy_image(image.wlx.mlx, image.img);
	return (image.img);
}

void	update(t_game *game, int x, int y)
{
	t_image	empty_image;

	empty_image.path = "texture/tiles/floor.xpm";
	empty_image.wlx = *game;
	put_image(empty_image, game->player.x, game->player.y);
	put_image(empty_image, x, y);
}
