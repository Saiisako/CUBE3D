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

// initialiser le joueur en fonction de la direction N S E W

void	find_player_position(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while(cube->map_cpy->grid[i])
	{
		j = 0;
		while (cube->map_cpy->grid[i][j])
		{
			if (cube->map_cpy->grid[i][j] == 'N' || cube->map_cpy->grid[i][j] == 'S' ||cube->map_cpy->grid[i][j] == 'E' ||cube->map_cpy->grid[i][j] == 'W')
			{
				cube->player->dir = cube->map_cpy->grid[i][j];
				cube->player->player_x = j;
				cube->player->player_y = i;
				printf("player x: %f\n", cube->player->player_x);
				printf("player y: %f\n", cube->player->player_y);
				printf("char player: %c\n", cube->map_cpy->grid[i][j]);
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
	
	printf("dir x %f dir y %f\n", cube->player->dir_x, cube->player->dir_y);
	printf("plane x %f plane y %f\n", cube->player->plane_x, cube->player->plane_y);
}