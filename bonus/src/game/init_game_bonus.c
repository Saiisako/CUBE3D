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

#include "../../../cube.h"

void	init_main_image(t_cube *cube)
{
	cube->img->img = mlx_new_image(cube->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cube->img->img)
		exit(1);
	cube->img->addr = mlx_get_data_addr(cube->img->img,
			&cube->img->bits_per_pixel,
			&cube->img->line_length,
			&cube->img->endian);
	if (!cube->img->addr)
		exit(1);
}

void	init_tex(t_cube *cube)
{
	cube->texture = malloc(sizeof(t_texture));
	if (!cube->texture)
		exit(1);
	cube->texture->north = NULL;
	cube->texture->south = NULL;
	cube->texture->west = NULL;
	cube->texture->east = NULL;
	cube->texture->floor = 0;
	cube->texture->ceiling = 0;
	cube->texture->hex_floor = 0x0;
	cube->texture->hex_ceiling = 0x0;
	cube->texture->size = TEXTURE_SIZE;
	cube->texture->index = 0;
	cube->texture->step = 0.0;
	cube->texture->pos = 0.0;
	cube->texture->x = 0;
	cube->texture->y = 0;
}

void	init_image(t_cube *cube, t_image *tmp, char *path)
{
	tmp->img = NULL;
	tmp->addr = NULL;
	tmp->color = NULL;
	tmp->bits_per_pixel = 0;
	tmp->line_length = 0;
	tmp->endian = 0;
	tmp->img = mlx_xpm_file_to_image(cube->mlx, path,
			&cube->texture->size,
			&cube->texture->size);
	if (!tmp->img)
		exit(1);
	tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bits_per_pixel,
			&tmp->line_length, &tmp->endian);
	tmp->color = (int *)tmp->addr;
	if (!tmp->addr)
		exit(1);
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
	init_input(cube);
}
