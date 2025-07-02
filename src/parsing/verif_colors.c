/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:59:08 by skock             #+#    #+#             */
/*   Updated: 2025/07/02 12:42:52 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	change_id_color_bool(t_cube *cube, int id, char *format)
{
	if (id == F)
	{
		check_duplicate_color(cube, id, format);
		cube->id->f_bool = true;
	}
	else if (id == C)
	{
		check_duplicate_color(cube, id, format);
		cube->id->c_bool = true;
	}
}

static void	verif_rgb(t_cube *cube, char *format, char **rgb)
{
	if (cube->color_c->r_color < 0 || cube->color_c->g_color < 0
		|| cube->color_c->b_color < 0)
	{
		free_array(rgb);
		free(format);
		ft_error_parsing(cube, "RGB color format must be 0-250 (X,X,X).");
	}
	else if (cube->color_f->r_color < 0 || cube->color_f->g_color < 0
		|| cube->color_f->b_color < 0)
	{
		free_array(rgb);
		free(format);
		ft_error_parsing(cube, "RGB color format must be 0-250 (X,X,X).");
	}
}

static void	fill_rgb_struct(t_cube *cube, char *format, char **rgb, int id)
{
	if (id == F)
	{
		cube->color_f->r_color = ft_atoi_rgb(rgb[0]);
		cube->color_f->g_color = ft_atoi_rgb(rgb[1]);
		cube->color_f->b_color = ft_atoi_rgb(rgb[2]);
		verif_rgb(cube, format, rgb);
	}
	else if (id == C)
	{
		cube->color_c->r_color = ft_atoi_rgb(rgb[0]);
		cube->color_c->g_color = ft_atoi_rgb(rgb[1]);
		cube->color_c->b_color = ft_atoi_rgb(rgb[2]);
		verif_rgb(cube, format, rgb);
	}
}

static void	check_format(t_cube *cube, char *format, int id)
{
	char	**rgb;
	int		i;

	i = 0;
	check_comma(cube, format);
	rgb = ft_split(format, ',');
	while (rgb[i])
		i++;
	while (rgb[i])
		i++;
	if (i != 3)
	{
		free(format);
		free_array(rgb);
		ft_error_parsing(cube, "rgb color format is not respected (X,X,X).");
	}
	fill_rgb_struct(cube, format, rgb, id);
	if (rgb)
		free_array(rgb);
}

void	check_colors(t_cube *cube, int id, int *i, int *j)
{
	char	*format;

	format = ft_substr(cube->map->grid[*i], (*j),
			(ft_strlen(cube->map->grid[*i]) - (*j)));
	check_format(cube, format, id);
	change_id_color_bool(cube, id, format);
	free(format);
}
