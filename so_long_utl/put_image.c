/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <mberri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:58:06 by mberri            #+#    #+#             */
/*   Updated: 2022/06/25 14:44:04 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_player(t_game *game, int w, int h)
{
	if (game->y == 2)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->image.p1,
			w * 64, h * 64);
	}
	else if (game->y == 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->image.p2,
			w * 64, h * 64);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->window, game->image.p1,
			w * +64, h * 64);
	}
}

void	put_collectible(t_game *game, int w, int h)
{
	mlx_put_image_to_window(game->mlx, game->window, game->image.f1,
		w * 64, h * 64);
}

void	put_door(t_game *game, int w, int h)
{
	if (game->all_col == game->collect_cnt)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->image.dr1,
			w * 64, h * 64);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->window, game->image.dr0,
			w * 64, h * 64);
	}
}

void	put_wall(t_game *game, int w, int h)
{
	mlx_put_image_to_window(game->mlx, game->window, game->image.wall,
		w * 64, h * 64);
}
