/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:50:55 by naankour          #+#    #+#             */
/*   Updated: 2025/07/15 12:50:55 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

static void	init_player(t_cube *cube)
{
	cube->player->dir = 0;
	cube->player->player_x = 0;
	cube->player->player_y = 0;
	cube->player->dir_x = 0;
	cube->player->dir_y = 0;
	cube->player->plane_x = 0;
	cube->player->plane_y = 0;
}

static void	init_ray(t_cube *cube)
{
	cube->ray->camerax = 0;
	cube->ray->ray_dir_x = 0;
	cube->ray->ray_dir_y = 0;
	cube->ray->map_x = 0;
	cube->ray->map_x = 0;
	cube->ray->delta_dist_x = 0;
	cube->ray->delta_dist_y = 0;
	cube->ray->side_dist_x = 0;
	cube->ray->side_dist_y = 0;
	cube->ray->step_x = 0;
	cube->ray->step_y = 0;
	cube->ray->hit = 0;
	cube->ray->side = 0;
	cube->ray->perp_wall_dist = 0;
	cube->ray->line_height = 0;
	cube->ray->draw_start = 0;
	cube->ray->draw_end = 0;
	cube->ray->wall_x = 0;
	cube->ray->tex_x = 0;
	cube->ray->tex_y = 0;
}

void	init_game(t_cube *cube)
{
	cube->player = malloc(sizeof(t_player));
	if (!cube->player)
		exit(1);
	cube->ray = malloc(sizeof(t_ray));
	if (!cube->ray)
		exit(1);
	cube->img = malloc(sizeof(t_image));
	if (!cube->img)
		exit(1);
	init_player(cube);
	init_ray(cube);
}
