/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:09:28 by skock             #+#    #+#             */
/*   Updated: 2025/06/27 17:11:30 by skock            ###   ########.fr       */
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
	if (cube->map->grid)
		free_array(cube->map->grid);
	if (cube->map)
		free(cube->map);
	if (cube->color_c)
		free(cube->color_c);
	if (cube->color_f)
		free(cube->color_f);
	free(cube);
}
