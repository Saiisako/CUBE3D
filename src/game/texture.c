/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:06:31 by naankour          #+#    #+#             */
/*   Updated: 2025/07/18 17:06:31 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	set_wall_direction(t_cube *cube)
{
	if (cube->ray->side == VERTICAL)
	{
		if (cube->ray->ray_dir_x > 0)
			cube->texture->index = EAST;
		else
			cube->texture->index = WEST;
	}
	else
	{
		if (cube->ray->ray_dir_y < 0)
			cube->texture->index = NORTH;
		else
			cube->texture->index = SOUTH;
	}
}

void	update_texture(t_cube *cube, int x)
{
	int	y;
	int	color;

	set_wall_direction(cube);
	cube->ray->tex_x = (int)(cube->ray->wall_x * TEXTURE_SIZE);
	cube->texture->step = 1 * TEXTURE_SIZE / cube->ray->line_height;
	cube->texture->pos = (cube->ray->draw_start - WIN_HEIGHT
			/ 2 + cube->ray->line_height / 2) * cube->texture->step;
	if (cube->texture->index == WEST || cube->texture->index == SOUTH)
		cube->ray->tex_x = TEXTURE_SIZE - cube->ray->tex_x - 1;
	y = cube->ray->draw_start;
	while (y < cube->ray->draw_end)
	{
		cube->ray->tex_y = (int)cube->texture->pos & (TEXTURE_SIZE - 1);
		cube->texture->pos += cube->texture->step;
		color = cube->texture_img[cube->texture->index][cube->ray->tex_y
			* cube->texture->size + cube->ray->tex_x];
		my_mlx_pixel_put(cube, x, y, color);
		y++;
	}
}
