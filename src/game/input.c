/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:01:17 by naankour          #+#    #+#             */
/*   Updated: 2025/07/18 17:01:17 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

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
	return (0);
}

int	on_key_release(int keycode, t_cube *cube)
{
	if (keycode == ESCAPE)
		cube->quit = 0;
	if (keycode == W)
		cube->move_up = 0;
	if (keycode == S)
		cube->move_down = 0;
	if (keycode == A)
		cube->move_left = 0;
	if (keycode == D)
		cube->move_right = 0;
	if (keycode == ROTATE_L)
		cube->rotate_left = 0;
	if (keycode == ROTATE_R)
		cube->rotate_right = 0;
	return (0);
}

void	init_input(t_cube *cube)
{
	cube->move_up = 0;
	cube->move_down = 0;
	cube->move_right = 0;
	cube->move_left = 0;
	cube->rotate_right = 0;
	cube->rotate_left = 0;
	cube->quit = 0;
}

void	quit_game(t_cube *cube)
{
	if (cube->quit)
		free_all(cube);
}

int	input(t_cube *cube)
{
	quit_game(cube);
	walk(cube);
	if (cube->rotate_left)
		rotate(cube, ROTATE_L);
	if (cube->rotate_right)
		rotate(cube, ROTATE_R);
	return (1);
}
