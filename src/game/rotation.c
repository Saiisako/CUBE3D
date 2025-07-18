/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:57:02 by naankour          #+#    #+#             */
/*   Updated: 2025/07/18 16:57:02 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	rotate_left_vector_dir(t_cube *cube)
{
	double	old_dir_x;

	old_dir_x = cube->player->dir_x;
	cube->player->dir_x = cube->player->dir_x * cos(-ROTATION_SPEED)
		- cube->player->dir_y * sin(-ROTATION_SPEED);
	cube->player->dir_y = old_dir_x * sin(-ROTATION_SPEED)
		+ cube->player->dir_y * cos(-ROTATION_SPEED);
}

void	rotate_left_vector_plane(t_cube *cube)
{
	double	old_plane_x;

	old_plane_x = cube->player->plane_x;
	cube->player->plane_x = cube->player->plane_x * cos(-ROTATION_SPEED)
		- cube->player->plane_y * sin(-ROTATION_SPEED);
	cube->player->plane_y = old_plane_x * sin(-ROTATION_SPEED)
		+ cube->player->plane_y * cos(-ROTATION_SPEED);
}

void	rotate_right_vector_dir(t_cube *cube)
{
	double	old_dir_x;

	old_dir_x = cube->player->dir_x;
	cube->player->dir_x = cube->player->dir_x * cos(ROTATION_SPEED)
		- cube->player->dir_y * sin(ROTATION_SPEED);
	cube->player->dir_y = old_dir_x * sin(ROTATION_SPEED)
		+ cube->player->dir_y * cos(ROTATION_SPEED);
}

void	rotate_right_vector_plane(t_cube *cube)
{
	double	old_plane_x;

	old_plane_x = cube->player->plane_x;
	cube->player->plane_x = cube->player->plane_x * cos(ROTATION_SPEED)
		- cube->player->plane_y * sin(ROTATION_SPEED);
	cube->player->plane_y = old_plane_x * sin(ROTATION_SPEED)
		+ cube->player->plane_y * cos(ROTATION_SPEED);
}

void	rotate(t_cube *cube, int keycode)
{
	if (keycode == ROTATE_L)
	{
		rotate_left_vector_dir(cube);
		rotate_left_vector_plane(cube);
		return ;
	}
	else if (keycode == ROTATE_R)
	{
		rotate_right_vector_dir(cube);
		rotate_right_vector_plane(cube);
		return ;
	}
}
