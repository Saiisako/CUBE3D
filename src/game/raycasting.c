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

void	dda_algo(t_cube *cube)
{
	while (cube->ray->hit == 0)
	{
		if (cube->ray->side_dist_x < cube->ray->side_dist_y)
		{
			cube->ray->side_dist_x += cube->ray->delta_dist_x;
			cube->ray->map_x += cube->ray->step_x;
			cube->ray->side = 0; // vertical: on a franchi une ligne verticale donc cest ce cote du mur qui a ete touche
		}
		else
		{
			cube->ray->side_dist_y += cube->ray->delta_dist_y;
			cube->ray->map_y += cube->ray->step_y;
			cube->ray->side = 1; // horizontal: on a franchi une ligne horizontale donc cest ce cote du mur qui a ete touche
		}
		if (cube->map_cpy->grid[cube->ray->map_y][cube->ray->map_x] == '1')
			cube->ray->hit = 1;
	}
}

void	init_ray_steps(t_cube *cube)
{
	if (cube->ray->ray_dir_x < 0)
	{
		cube->ray->step_x = -1;
		cube->ray->side_dist_x = (cube->player->player_x - cube->ray->map_x)
			* cube->ray->delta_dist_x;
	}
	else
	{
		cube->ray->step_x = +1;
		cube->ray->side_dist_x = (cube->ray->map_x + 1 - cube->player->player_x)
			* cube->ray->delta_dist_x;
	}
	if (cube->ray->ray_dir_y < 0)
	{
		cube->ray->step_y = -1;
		cube->ray->side_dist_y = (cube->player->player_y - cube->ray->map_y)
			* cube->ray->delta_dist_y;
	}
	else
	{
		cube->ray->step_y = +1;
		cube->ray->side_dist_y = (cube->ray->map_y + 1 - cube->player->player_y)
			* cube->ray->delta_dist_y;
	}
}

void	init_ray_data(t_cube *cube, int x)
{
	cube->ray->camerax = 2 * x / (double)WIN_WIDTH - 1;
	cube->ray->ray_dir_x = cube->player->dir_x + (cube->player->plane_x
			* cube->ray->camerax);
	cube->ray->ray_dir_y = cube->player->dir_y + (cube->player->plane_y
			* cube->ray->camerax);
	cube->ray->map_x = (int)cube->player->player_x;
	cube->ray->map_y = (int)cube->player->player_y;
	cube->ray->delta_dist_x = fabs(1 / cube->ray->ray_dir_x);
	cube->ray->delta_dist_y = fabs(1 / cube->ray->ray_dir_y);
}

void	calculate_line(t_cube *cube)
{
	if (cube->ray->side == 0)
		cube->ray->perp_wall_dist = (cube->ray->map_x
				- cube->player->player_x + (1 - cube->ray->step_x) / 2)
			/ cube->ray->ray_dir_x;
	else
		cube->ray->perp_wall_dist = (cube->ray->map_y
				- cube->player->player_y + (1 - cube->ray->step_y) / 2)
			/ cube->ray->ray_dir_y;
	cube->ray->line_height = (int)(WIN_HEIGHT / cube->ray->perp_wall_dist);
}


int	raycasting(t_cube *cube)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		cube->ray->hit = 0;
		init_ray_data(cube, x);
		init_ray_steps(cube);
		dda_algo(cube); // si pb revoir pourquoi 0.25
		calculate_line(cube);
		//dessiner la colonne
		x++;
	}
	return (0);
}
