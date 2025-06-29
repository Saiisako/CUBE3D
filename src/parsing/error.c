/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:09:26 by skock             #+#    #+#             */
/*   Updated: 2025/06/27 17:17:07 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	ft_error_fd(t_cube *cube)
{
	ft_printf("Error: Unable to open the file.\n");
	free(cube->color_c);
	free(cube->color_f);
	free(cube->id);
	free(cube);
	exit(1);
}

void	ft_error_parsing(t_cube *cube, const char *str)
{
	if (cube->map->grid)
		free_array(cube->map->grid);
	if (cube->map)
		free(cube->map);
	if (cube->id)
		free(cube->id);
	if (cube->color_c)
		free(cube->color_c);
	if (cube->color_f)
		free(cube->color_f);
	if (cube)
		free(cube);
	ft_printf("Error parsing: %s\n", str);
	exit(1);
}
