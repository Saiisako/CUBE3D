/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:19:39 by skock             #+#    #+#             */
/*   Updated: 2025/07/18 14:03:32 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return;
	dst = cube->img->addr + (y * cube->img->line_length + x * (cube->img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	render(t_cube *cube)
{
	mlx_destroy_image(cube->mlx, cube->img->img);
	cube->img->img = mlx_new_image(cube->mlx, WIN_WIDTH, WIN_HEIGHT);
	cube->img->addr = mlx_get_data_addr(cube->img->img, &cube->img->bits_per_pixel, &cube->img->line_length, &cube->img->endian);
	raycasting(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img->img, 0, 0);
	return (1);
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

	tmp->img = mlx_xpm_file_to_image(cube->mlx, path, &cube->texture->size, &cube->texture->size);
	if (!tmp->img)
		exit(1);
	tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bits_per_pixel,
			&tmp->line_length, &tmp->endian);
	tmp->color = (int*)tmp->addr;
	if (!tmp->addr)
		exit(1);
}

int *xpm_to_image(t_cube *cube, char *path)
{
	t_image tmp;
	int *buffer;
	int x;
	int y;

	init_image(cube, &tmp, path);
	buffer = ft_calloc(TEXTURE_SIZE * TEXTURE_SIZE, sizeof(int));
	if (!buffer)
		exit(1);
	y = 0;
	while (y < TEXTURE_SIZE)
	{
		x = 0;
		while (x < TEXTURE_SIZE)
		{
			buffer[y * TEXTURE_SIZE + x] = tmp.color[y * TEXTURE_SIZE + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(cube->mlx, tmp.img);
	return (buffer);
}

void	load_textures(t_cube *cube)
{
	cube->texture_img = ft_calloc(5, sizeof(int *));
	if (!cube->texture_img)
		exit(1);
	init_tex(cube);
	cube->texture_img[NORTH] = xpm_to_image(cube, cube->path[NORTH]);
	cube->texture_img[SOUTH] = xpm_to_image(cube, cube->path[SOUTH]);
	cube->texture_img[EAST] = xpm_to_image(cube, cube->path[EAST]);
	cube->texture_img[WEST] = xpm_to_image(cube, cube->path[WEST]);
}
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

void	walk(t_cube *cube, int keycode)
{
	if (keycode == W)
	{
		if (cube->player->player_y - MOVE_SPEED < 1)
			return ;
		cube->player->player_x = cube->player->player_x + cube->player->dir_x * MOVE_SPEED;
		cube->player->player_y = cube->player->player_y + cube->player->dir_y * MOVE_SPEED;
	}
	else if (keycode == S)
	{
		if (cube->player->player_y + MOVE_SPEED > cube->map_cpy->grid_height - 1)
			return ;
		cube->player->player_x = cube->player->player_x - cube->player->dir_x * MOVE_SPEED;
		cube->player->player_y = cube->player->player_y - cube->player->dir_y * MOVE_SPEED;
	}
	else if (keycode == A)
	{
		if (cube->player->player_x - MOVE_SPEED < 1)
			return ;
		cube->player->player_x = cube->player->player_x - cube->player->plane_x * MOVE_SPEED;
		cube->player->player_y = cube->player->player_y - cube->player->plane_y * MOVE_SPEED;
	}
	else if (keycode == D)
	{
		if (cube->player->player_x + MOVE_SPEED > cube->map_cpy->grid_length - 1)
			return ;
		cube->player->player_x = cube->player->player_x + cube->player->plane_x * MOVE_SPEED;
		cube->player->player_y = cube->player->player_y + cube->player->plane_y * MOVE_SPEED;
	}
}


void	rotate(t_cube *cube, int keycode)
{
	double old_dir_x;
	double old_plane_x;

	if (keycode == ROTATE_L)
	{
		old_dir_x = cube->player->dir_x;
		cube->player->dir_x = cube->player->dir_x * cos(-ROTATION_SPEED) - cube->player->dir_y * sin(-ROTATION_SPEED);
		cube->player->dir_y = old_dir_x * sin(-ROTATION_SPEED) + cube->player->dir_y * cos(-ROTATION_SPEED);
		old_plane_x = cube->player->plane_x;
		cube->player->plane_x = cube->player->plane_x * cos(-ROTATION_SPEED) - cube->player->plane_y * sin(-ROTATION_SPEED);
		cube->player->plane_y = old_plane_x * sin(-ROTATION_SPEED) + cube->player->plane_y * cos(-ROTATION_SPEED);
		return ;
	}
	else if (keycode == ROTATE_R)
	{
		old_dir_x = cube->player->dir_x;
		cube->player->dir_x = cube->player->dir_x * cos(ROTATION_SPEED) - cube->player->dir_y * sin(ROTATION_SPEED);
		cube->player->dir_y = old_dir_x * sin(ROTATION_SPEED) + cube->player->dir_y * cos(ROTATION_SPEED);
		old_plane_x = cube->player->plane_x;
		cube->player->plane_x = cube->player->plane_x * cos(ROTATION_SPEED) - cube->player->plane_y * sin(ROTATION_SPEED);
		cube->player->plane_y = old_plane_x * sin(ROTATION_SPEED) + cube->player->plane_y * cos(ROTATION_SPEED);
		return ;
	}
}

void	quit_game(t_cube *cube, int keycode)
{
	(void)cube;
	if (keycode == ESCAPE)
		exit(1);
}

int	move(int keycode, void *c)
{
	t_cube *cube = (t_cube*)c;

	quit_game(cube, keycode);
	walk(cube, keycode);
	rotate(cube, keycode);
	return (1);
}

void	graphic(t_cube *cube)
{
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	init_game(cube);
	load_textures(cube);
	init_main_image(cube);
	find_player_position(cube);
	init_player_position(cube);
	raycasting(cube);
	mlx_key_hook(cube->win, move, cube);
	mlx_loop_hook(cube->mlx, render, cube);
	mlx_loop(cube->mlx);
	return ;
}
