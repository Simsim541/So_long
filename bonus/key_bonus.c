/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <mberri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:21:53 by mberri            #+#    #+#             */
/*   Updated: 2022/06/24 21:34:29 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_up(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->str))
	{
		if (game->str[i] == 'P')
			break ;
	}
	if (game->str[i - game->wid] == 'C')
		game->collect_cnt++;
	if (game->str[i - game->wid] == 'E' && game->all_col == game->collect_cnt)
		win_game(game);
	if (game->str[i - game->wid] == 'V')
		lose_game(game);
	if (game->str[i - game->wid] != '1' && game->str[i - game->wid] != 'E')
	{
		game->str[i] = '0';
		game->str[i - game->wid] = 'P';
		game->walk_cnt++;
		set_img(game);
	}
}

void	move_down(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->str))
	{
		if (game->str[i] == 'P')
			break ;
	}
	if (game->str[i + game->wid] == 'C')
		game->collect_cnt++;
	if (game->str[i + game->wid] == 'E' && game->all_col == game->collect_cnt)
		win_game(game);
	if (game->str[i + game->wid] == 'V')
		lose_game(game);
	if (game->str[i + game->wid] != '1' && game->str[i + game->wid] != 'E')
	{
		game->str[i] = '0';
		game->str[i + game->wid] = 'P';
		game->walk_cnt++;
		set_img(game);
	}
}

void	move_left(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->str))
	{
		if (game->str[i] == 'P')
			break ;
	}
	if (game->str[i - 1] == 'C')
		game->collect_cnt++;
	if (game->str[i - 1] == 'E' && game->all_col == game->collect_cnt)
		win_game(game);
	if (game->str[i - 1] == 'V')
		lose_game(game);
	if (game->str[i - 1] != '1' && game->str[i - 1] != 'E')
	{
		game->str[i] = '0';
		game->str[i - 1] = 'P';
		game->walk_cnt++;
		game->y = 1;
		set_img(game);
	}
}

void	move_right(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->str))
	{
		if (game->str[i] == 'P')
			break ;
	}
	if (game->str[i + 1] == 'C')
		game->collect_cnt++;
	if (game->str[i + 1] == 'E' && game->all_col == game->collect_cnt)
		win_game(game);
	if (game->str[i + 1] == 'V')
		lose_game(game);
	if (game->str[i + 1] != '1' && game->str[i + 1] != 'E')
	{
		game->str[i] = '0';
		game->str[i + 1] = 'P';
		game->walk_cnt++;
		game->y = 2;
		set_img(game);
	}
}
