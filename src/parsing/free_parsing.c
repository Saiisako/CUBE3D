/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:09:28 by skock             #+#    #+#             */
/*   Updated: 2025/07/19 12:58:10 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	free_tab(int **array)
{
	int	i;

	i = -1;
	while (array[++i])
	{
		if (array[i])
			free(array[i]);
	}
	free(array);
}

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
	{
		if (array[i])
			free(array[i]);
	}
	free(array);
}

static void	free_all1(t_cube *cube)
{
	if (cube->map_cpy->grid)
		free_array(cube->map_cpy->grid);
	if (cube->map->grid)
		free_array(cube->map->grid);
	if (cube->map)
		free(cube->map);
	if (cube->map_cpy)
		free(cube->map_cpy);
	if (cube->color_c)
		free(cube->color_c);
	if (cube->color_f)
		free(cube->color_f);
	if (cube->id)
		free(cube->id);
	if (cube->player)
		free(cube->player);
	if (cube->ray)
		free(cube->ray);
	if (cube->path)
		free_array(cube->path);
}

int	free_all(t_cube *cube)
{
	free_all1(cube);
	if (cube->texture_img)
		free_tab(cube->texture_img);
	if (cube->texture)
		free(cube->texture);
	mlx_destroy_image(cube->mlx, cube->img->img);
	if (cube->img)
		free(cube->img);
	mlx_destroy_window(cube->mlx, cube->win);
	mlx_destroy_display(cube->mlx);
	if (cube->mlx)
		free(cube->mlx);
	free(cube);
	exit(1);
	return (0);
}
