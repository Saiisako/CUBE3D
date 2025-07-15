/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:12:21 by skock             #+#    #+#             */
/*   Updated: 2025/07/15 16:03:52 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

static void	init_colors(t_cube *cube)
{
	cube->color_f->r_color = 0;
	cube->color_f->g_color = 0;
	cube->color_f->b_color = 0;
	cube->color_c->r_color = 0;
	cube->color_c->g_color = 0;
	cube->color_c->b_color = 0;
}

// static void	init_player(t_cube *cube)
// {
// 	cube->player->dir = 0;
// 	cube->player->player_x = 0;
// 	cube->player->player_y = 0;
// 	cube->player->dir_x = 0;
// 	cube->player->dir_y = 0;
// 	cube->player->plane_x = 0;
// 	cube->player->plane_y = 0;
// }

// static void	init_ray(t_cube *cube)
// {
// 	cube->ray->camerax = 0;
// 	cube->ray->ray_dir_x = 0;
// 	cube->ray->ray_dir_y = 0;
// 	cube->ray->map_x = 0;
// 	cube->ray->map_x = 0;
// 	cube->ray->delta_dist_x = 0;
// 	cube->ray->delta_dist_y = 0;
// 	cube->ray->side_dist_x = 0;
// 	cube->ray->side_dist_y = 0;
// 	cube->ray->step_x = 0;
// 	cube->ray->step_y = 0;
// 	cube->ray->hit = 0;
// 	cube->ray->side = 0;
// 	// cube->ray->perp_wall_dist = 0;
// }

static void	init_cube(t_cube *cube, char **av)
{
	cube->av = av;
	cube->file_path = av[1];
	cube->id->no_bool = false;
	cube->id->so_bool = false;
	cube->id->we_bool = false;
	cube->id->ea_bool = false;
	cube->id->f_bool = false;
	cube->id->c_bool = false;
	cube->count = 0;
}

void	init_struct(t_cube *cube, char **av)
{
	cube->id = malloc(sizeof(t_id));
	if (!cube->id)
		exit(1);
	cube->color_f = malloc(sizeof(t_color));
	if (!cube->color_f)
		exit(1);
	cube->color_c = malloc(sizeof(t_color));
	if (!cube->color_c)
		exit(1);
	cube->path = malloc(sizeof(char *) * 5);
	if (!cube->path)
		exit(1);
	cube->path[0] = ft_strdup("nothing");
	cube->path[1] = ft_strdup("nothing");
	cube->path[2] = ft_strdup("nothing");
	cube->path[3] = ft_strdup("nothing");
	cube->path[4] = NULL;
	init_colors(cube);
	init_cube(cube, av);
}
