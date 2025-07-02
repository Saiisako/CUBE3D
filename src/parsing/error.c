/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:09:26 by skock             #+#    #+#             */
/*   Updated: 2025/07/02 10:42:57 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	ft_error_fd(t_cube *cube)
{
	ft_printf("Error: Unable to open the file.");
	free(cube->color_c);
	free(cube->color_f);
	free(cube->id);
	free(cube);
	exit(1);
}

void	ft_error_parsing_empty_map(t_cube *cube, const char *str)
{
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

void	ft_error_parsing_map(t_cube *cube, const char *str)
{
	if (cube->map_cpy->grid)
		free_array(cube->map_cpy->grid);
	if (cube->map->grid)
		free_array(cube->map->grid);
	if (cube->map_cpy)
		free(cube->map_cpy);
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

void	error_comma(t_cube *cube, char *format)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
	{
		free(format);
		ft_error_parsing(cube, "rgb color format is not respected (X,X,X).");
	}
}
