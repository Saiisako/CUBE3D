/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:52:42 by skock             #+#    #+#             */
/*   Updated: 2025/07/01 11:52:56 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int	update_start(t_cube *cube, int start)
{
	while (cube->map->grid[start])
	{
		if (is_valid_start(cube->map->grid[start]))
		{
			return (start);
		}
		start++;
	}
	ft_error_parsing(cube, "No map detected.\n");
	return (start);
}

int	update_height(t_cube *cube, int start)
{
	int	i;

	i = 0;
	while (cube->map->grid[start])
	{
		start++;
		i++;
	}
	return (i);
}

int	get_longest_line(char **map, int i)
{
	int	l;
	int	tmp;

	l = 0;
	while (map[i])
	{
		tmp = ft_strlen(map[i]);
		if (tmp > l)
			l = tmp;
		i++;
	}
	return (l);
}
