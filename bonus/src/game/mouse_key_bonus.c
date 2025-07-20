/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:54:47 by naankour          #+#    #+#             */
/*   Updated: 2025/07/20 18:54:47 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube_bonus.h"

void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = cube->img->addr + (y * cube->img->line_length + x
			* (cube->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	on_key_press2(t_cube *cube)
{
	if (!cube->open_door)
		cube->open_door = 1;
	else
		cube->open_door = 0;
}

int	on_key_press(int keycode, t_cube *cube)
{
	if (keycode == ESCAPE)
		cube->quit = 1;
	if (keycode == W)
		cube->move_up = 1;
	if (keycode == S)
		cube->move_down = 1;
	if (keycode == A)
		cube->move_left = 1;
	if (keycode == D)
		cube->move_right = 1;
	if (keycode == ROTATE_L)
		cube->rotate_left = 1;
	if (keycode == ROTATE_R)
		cube->rotate_right = 1;
	if (keycode == DAY)
		cube->day = 1;
	if (keycode == NIGHT)
		cube->night = 1;
	if (keycode == OPEN)
		on_key_press2(cube);
	return (0);
}

void	bonus_mouse(t_cube *cube)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(cube->mlx, cube->win, &x, &y);
	if (x < WIN_WIDTH / 3)
		rotate(cube, ROTATE_L);
	else if (x > 2 * WIN_WIDTH / 3)
		rotate(cube, ROTATE_R);
}
