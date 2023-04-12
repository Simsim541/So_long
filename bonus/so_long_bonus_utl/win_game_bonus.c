/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <mberri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:32:20 by mberri            #+#    #+#             */
/*   Updated: 2022/06/24 19:39:19 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	win_game(t_game *final)
{
	final->walk_cnt++;
	ft_putstr("congratulations you finish game with :");
	ft_putnbr(final->walk_cnt);
	ft_putstr(" step\n");
	exit(0);
}
