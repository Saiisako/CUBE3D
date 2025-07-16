/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:19:39 by skock             #+#    #+#             */
/*   Updated: 2025/07/16 18:14:09 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int	render(t_cube *cube)
{
	raycasting(cube);
	return (0);
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
}

void	init_image(t_cube *cube, t_image *tmp, char *path)
{
	tmp->img = NULL;
	tmp->addr = NULL;
	tmp->bits_per_pixel = 0;
	tmp->line_length = 0;
	tmp->endian = 0;

	tmp->img = mlx_xpm_file_to_image(cube->mlx, path, &cube->texture->size, &cube->texture->size);
	if (!tmp->img)
	{
		printf("here\n");
		exit(1);
	}
	tmp->addr = mlx_get_data_addr(tmp->img, &tmp->bits_per_pixel,
			&tmp->line_length, &tmp->endian);
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
	buffer = ft_calloc(1, sizeof(int) * TEXTURE_SIZE * TEXTURE_SIZE);
	if (!buffer)
		exit(1);
	y = 0;
	while (y < TEXTURE_SIZE)
	{
		x = 0;
		while (x < TEXTURE_SIZE)
		{
			buffer[y * TEXTURE_SIZE + x] = tmp.addr[y * TEXTURE_SIZE + x];
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
	init_game(cube);
	load_textures(cube);
	printf("hre\n");
	find_player_position(cube);
	init_player_position(cube);
	raycasting(cube);
	mlx_loop_hook(cube->mlx, render, cube);
	mlx_loop(cube->mlx);
	return ;
}
