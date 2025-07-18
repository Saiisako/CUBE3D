/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:52:43 by naankour          #+#    #+#             */
/*   Updated: 2025/07/07 10:52:43 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	init_player(t_cube *cube)
{
	cube->player->dir = 0;
	cube->player->player_x = 0;
	cube->player->player_y = 0;
	cube->player->dir_x = 0;
	cube->player->dir_y = 0;
	cube->player->plane_x = 0;
	cube->player->plane_y = 0;
}

void	find_player_position(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map_cpy->grid[i])
	{
		j = 0;
		while (cube->map_cpy->grid[i][j])
		{
			if (cube->map_cpy->grid[i][j] == 'N'
				|| cube->map_cpy->grid[i][j] == 'S'
				|| cube->map_cpy->grid[i][j] == 'E'
				|| cube->map_cpy->grid[i][j] == 'W')
			{
				cube->player->dir = cube->map_cpy->grid[i][j];
				cube->player->player_x = j + 0.5;
				cube->player->player_y = i + 0.5;
			}
			j++;
		}
		i++;
	}
}

void	init_player_position(t_cube *cube)
{
	if (cube->player->dir == 'N')
	{
		cube->player->dir_x = 0;
		cube->player->dir_y = -1;
	}
	else if (cube->player->dir == 'S')
	{
		cube->player->dir_x = 0;
		cube->player->dir_y = 1;
	}
	else if (cube->player->dir == 'E')
	{
		cube->player->dir_x = 1;
		cube->player->dir_y = 0;
	}
	else if (cube->player->dir == 'W')
	{
		cube->player->dir_x = -1;
		cube->player->dir_y = 0;
	}
	cube->player->plane_x = -(cube->player->dir_y) * 0.66;
	cube->player->plane_y = (cube->player->dir_x) * 0.66;
}
