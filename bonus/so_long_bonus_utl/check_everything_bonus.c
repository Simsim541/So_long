/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_everything_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <mberri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:24:51 by mberri            #+#    #+#             */
/*   Updated: 2022/06/25 16:53:47 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_all(t_game *j)
{
	int	i;

	i = 0;
	while (j->str[i])
	{
		if (j->str[i] != '1' && j->str[i] != '0' && j->str[i] != 'V'
			&& j->str[i] != 'P' && j->str[i] != 'C' && j->str[i] != 'E')
		{
			print_error("Unknown Character in map !?\n");
		}
		i++;
	}
}

int	check_extension(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (str[size - 1] == 'r' && str[size - 2] == 'e'
		&& str[size - 3] == 'b' && str[size - 4] == '.')
		return (1);
	return (0);
}

int	check(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 32)
			return (1);
		i++;
	}
	return (0);
}

void	ft_ft(char **line, int fd)
{
	while (*line)
	{
		if (check(*line))
			break ;
		free(*line);
		*line = get_next_line(fd);
	}
}
