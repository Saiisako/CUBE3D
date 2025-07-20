/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:19:39 by skock             #+#    #+#             */
/*   Updated: 2025/07/20 18:55:44 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube_bonus.h"

int	render(t_cube *cube)
{
	bonus_mouse(cube);
	input(cube);
	mlx_destroy_image(cube->mlx, cube->img->img);
	cube->img->img = mlx_new_image(cube->mlx, WIN_WIDTH, WIN_HEIGHT);
	cube->img->addr = mlx_get_data_addr(cube->img->img,
			&cube->img->bits_per_pixel,
			&cube->img->line_length, &cube->img->endian);
	raycasting(cube);
	render_minimap(cube);
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

int	*xpm_to_image_door(t_cube *cube, int door_state)
{
	t_image	tmp;
	int		*buffer;
	int		x;
	int		y;

	if (door_state == DOOR_CLOSE)
		init_image(cube, &tmp, "assets/door_close.xpm");
	else if (door_state == DOOR_OPEN)
		init_image(cube, &tmp, "assets/door.xpm");
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
	cube->texture_img = ft_calloc(7, sizeof(int *));
	if (!cube->texture_img)
		exit(1);
	init_tex(cube);
	cube->texture_img[NORTH] = xpm_to_image(cube, cube->path[NORTH]);
	cube->texture_img[SOUTH] = xpm_to_image(cube, cube->path[SOUTH]);
	cube->texture_img[EAST] = xpm_to_image(cube, cube->path[EAST]);
	cube->texture_img[WEST] = xpm_to_image(cube, cube->path[WEST]);
	cube->texture_img[DOOR_OPEN] = xpm_to_image_door(cube, DOOR_OPEN);
	cube->texture_img[DOOR_CLOSE] = xpm_to_image_door(cube, DOOR_CLOSE);
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
	mlx_hook(cube->win, 2, 1L << 0, on_key_press, cube);
	mlx_hook(cube->win, 3, 1L << 1, on_key_release, cube);
	mlx_hook(cube->win, 17, 0, free_all, cube);
	mlx_loop_hook(cube->mlx, render, cube);
	mlx_loop(cube->mlx);
	return ;
}
