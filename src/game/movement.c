/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:00:37 by naankour          #+#    #+#             */
/*   Updated: 2025/07/18 17:00:37 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	move_forward(t_cube *cube)
{
	double	new_x;
	double	new_y;

	new_x = cube->player->player_x + cube->player->dir_x * MOVE_SPEED;
	new_y = cube->player->player_y + cube->player->dir_y * MOVE_SPEED;
	if (new_x < 1 || new_x > cube->map_cpy->grid_length - 1 || new_y < 1
		|| new_y > cube->map_cpy->grid_height - 1)
		return ;
	cube->player->player_x = new_x;
	cube->player->player_y = new_y;
}

void	move_backward(t_cube *cube)
{
	double	new_x;
	double	new_y;

	new_x = cube->player->player_x - cube->player->dir_x * MOVE_SPEED;
	new_y = cube->player->player_y - cube->player->dir_y * MOVE_SPEED;
	if (new_x < 1 || new_x > cube->map_cpy->grid_length - 1 || new_y < 1
		|| new_y > cube->map_cpy->grid_height - 1)
		return ;
	cube->player->player_x = new_x;
	cube->player->player_y = new_y;
}

void	move_left(t_cube *cube)
{
	double	new_x;
	double	new_y;

	new_x = cube->player->player_x - cube->player->plane_x * MOVE_SPEED;
	new_y = cube->player->player_y - cube->player->plane_y * MOVE_SPEED;
	if (new_x < 1 || new_x > cube->map_cpy->grid_length - 1 || new_y < 1
		|| new_y > cube->map_cpy->grid_height - 1)
		return ;
	cube->player->player_x = new_x;
	cube->player->player_y = new_y;
}

void	move_right(t_cube *cube)
{
	double	new_x;
	double	new_y;

	new_x = cube->player->player_x + cube->player->plane_x * MOVE_SPEED;
	new_y = cube->player->player_y + cube->player->plane_y * MOVE_SPEED;
	if (new_x < 1 || new_x > cube->map_cpy->grid_length - 1 || new_y < 1
		|| new_y > cube->map_cpy->grid_height - 1)
		return ;
	cube->player->player_x = new_x;
	cube->player->player_y = new_y;
}

void	walk(t_cube *cube, int keycode)
{
	if (keycode == W)
		move_forward(cube);
	else if (keycode == S)
		move_backward(cube);
	else if (keycode == A)
		move_left(cube);
	else if (keycode == D)
		move_right(cube);
}
