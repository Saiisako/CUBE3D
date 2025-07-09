/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:43:55 by naankour          #+#    #+#             */
/*   Updated: 2025/07/09 17:43:55 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	init_ray_data(t_cube *cube, int x)
{
	cube->ray->camerax = 2 * x / (double)WIN_WIDTH - 1;
	cube->ray->ray_dir_x = cube->player->dir_x + (cube->player->plane_x * cube->ray->camerax);
	cube->ray->ray_dir_y = cube->player->dir_y + (cube->player->plane_y * cube->ray->camerax);
	cube->ray->map_x = (int)cube->player->player_x;
	cube->ray->map_y = (int)cube->player->player_y;
	// cube->ray->delta_dist_x = 0;
	// cube->ray->delta_dist_y = 0;

	// cube->ray->side_dist_x = 0;
	// cube->ray->side_dist_y = 0;
	// cube->ray->step_x = 0;
	// cube->ray->step_y = 0;
	// cube->ray->hit = 0;
	// cube->ray->side = 0;
}

