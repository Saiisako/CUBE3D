/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:09:28 by skock             #+#    #+#             */
/*   Updated: 2025/07/15 15:59:32 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

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

void	free_all(t_cube *cube)
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
	free(cube);
}
