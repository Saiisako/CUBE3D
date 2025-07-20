/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:05:33 by naankour          #+#    #+#             */
/*   Updated: 2025/07/18 17:05:33 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube_bonus.h"

void	draw_square(t_cube *cube, int x, int y, int color)
{
	int	i;
	int	j;
	int	size;

	size = 4;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(cube, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_square2(t_cube *cube, int x, int y, int color)
{
	int	i;
	int	j;
	int	size;

	size = MINIMAP_SCALE;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(cube, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_player_color(t_cube *cube, int scale)
{
	int	x;
	int	y;

	x = MINIMAP_START + (int)(cube->player->player_x * scale);
	y = MINIMAP_START + (int)(cube->player->player_y * scale);
	draw_square(cube, x - 2, y - 2, 0xFF0000);
}

void	render_minimap(t_cube *cube)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	while (++y < cube->map_cpy->grid_height)
	{
		x = -1;
		while (++x < cube->map_cpy->grid_length)
		{
			if (cube->map_cpy->grid[y][x] == '1'
				|| cube->map_cpy->grid[y][x] == 'X')
				color = 0x444444;
			else if (is_walkable_or_player(cube->map_cpy->grid[y][x]))
				color = 0xAAAAAA;
			else
				color = 0xFFB6C1;
			draw_square2(cube, (MINIMAP_START + x * MINIMAP_SCALE),
				(MINIMAP_START + y * MINIMAP_SCALE), color);
		}
	}
	draw_player_color(cube, MINIMAP_SCALE);
}

void	render_floor_ceiling(t_cube *cube)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(cube, x, y, cube->color_c->color);
			x++;
		}
		y++;
	}
	y = WIN_HEIGHT / 2 - 1;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(cube, x, y, cube->color_f->color);
			x++;
		}
		y++;
	}
}
