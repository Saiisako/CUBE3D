/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:19:39 by skock             #+#    #+#             */
/*   Updated: 2025/07/16 16:08:33 by naankour         ###   ########.fr       */
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

int *xpm_to_image(t_cube *cube, char *path)
{
	static int d = 0;
	int i;

	printf("%d", d++);
	i = 0;
	(void)path;
	(void)cube;
	printf("%s\n", path);
	return (NULL);
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
	find_player_position(cube);
	init_player_position(cube);
	raycasting(cube);
	mlx_loop_hook(cube->mlx, render, cube);
	mlx_loop(cube->mlx);
	return ;
}
