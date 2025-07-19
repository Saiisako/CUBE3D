/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:19:39 by skock             #+#    #+#             */
/*   Updated: 2025/07/19 08:24:49 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = cube->img->addr + (y * cube->img->line_length + x
			* (cube->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int on_key_press(int keycode, t_cube *cube)
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

int on_key_release(int keycode, t_cube *cube)
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

int	render(t_cube *cube)
{
	int x;
	int y;
	mlx_mouse_get_pos(cube->mlx, cube->win, &x, &y);
	if (x < WIN_WIDTH / 3)
		rotate(cube, ROTATE_L);
	else if (x > 2 * WIN_WIDTH / 3)
		rotate(cube, ROTATE_R);
	input(cube);
	mlx_destroy_image(cube->mlx, cube->img->img);
	cube->img->img = mlx_new_image(cube->mlx, WIN_WIDTH, WIN_HEIGHT);
	cube->img->addr = mlx_get_data_addr(cube->img->img,
			&cube->img->bits_per_pixel,
			&cube->img->line_length, &cube->img->endian);
	raycasting(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img->img, 0, 0);
	return (1);
}

int	*xpm_to_image(t_cube *cube, char *path)
{
	t_image	tmp;
	int		*buffer;
	int		x;
	int		y;

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

void	graphic(t_cube *cube)
{
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	cube->move_up = 0;
	cube->move_down = 0;
	cube->move_right = 0;
	cube->move_left = 0;
	cube->rotate_right = 0;
	cube->rotate_left = 0;
	cube->quit = 0;
	init_game(cube);
	load_textures(cube);
	init_main_image(cube);
	find_player_position(cube);
	init_player_position(cube);
	raycasting(cube);
	mlx_hook(cube->win, 2, 1L << 0, on_key_press, cube);    // KeyPress
	mlx_hook(cube->win, 3, 1L << 1, on_key_release, cube);
	mlx_loop_hook(cube->mlx, render, cube);
	mlx_loop(cube->mlx);
	return ;
}
