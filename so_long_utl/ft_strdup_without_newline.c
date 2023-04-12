/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_without_newline.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <mberri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:40:08 by mberri            #+#    #+#             */
/*   Updated: 2022/06/25 14:10:16 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup_without_newline(char *string)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(ft_strlen(string) + 1);
	if (!ptr)
		return (0);
	while (string[i] != '\0' && string[i] != '\n')
	{
		ptr[i] = string[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
