/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <mberri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:36:55 by mberri            #+#    #+#             */
/*   Updated: 2022/06/25 17:00:56 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game, char *filename)
{
	char	*line;
	char	*tmp;
	int		fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (fd < 0 || !line)
		print_error("Map is empty\n");
	ft_ft(&line, fd);
	game->wid = ft_strlen(line) - 1;
	game->str = ft_strdup_without_newline(line);
	game->hei++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && check(line))
		{	
			game->hei++;
			tmp = game->str;
			game->str = ft_strjoin_without_newline(game->str, line);
			free(tmp);
		}
	}
	close(fd);
}

void	check_wall(t_game *check)
{
	int	i;

	i = 0;
	while (i < ft_strlen(check->str))
	{
		if (i < check->wid)
		{
			if (check->str[i] != '1')
				print_error("Wall is missing \n");
		}
		else if (i % check->wid == 0 || i % check->wid == check->wid - 1)
		{
			if (check->str[i] != '1')
				print_error("Wall is missing\n");
		}
		else if (i > (ft_strlen(check->str) - check->wid))
		{
			if (check->str[i] != '1')
				print_error("Wall is missing\n");
		}
		i++;
	}
}

void	check_params(t_game *param)
{
	int	i;
	int	num_e;
	int	num_p;

	i = 0;
	num_e = 0;
	param->all_col = 0;
	num_p = 0;
	while (i++ < ft_strlen(param->str))
	{
		if (param->str[i] == 'E')
			num_e++;
		if (param->str[i] == 'C')
			param->all_col++;
		if (param->str[i] == 'P')
			num_p++;
	}
	if (num_e == 0)
		print_error("Map at least should have one exit\n");
	if (param->all_col == 0)
		print_error("Map at least should have one collectible\n");
	if (num_p != 1)
		print_error("Map at least should have just one player\n");
}

void	general_check(t_game *y)
{
	y->y = 0;
	if ((y->wid * y->hei) != ft_strlen(y->str))
		print_error("Map must be rectangle\n");
	check_wall(y);
	check_params(y);
	check_all(y);
	y->walk_cnt = 0;
}
