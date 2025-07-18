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

#include "../../cube.h"

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
