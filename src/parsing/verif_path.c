/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:57:53 by skock             #+#    #+#             */
/*   Updated: 2025/06/30 08:59:53 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	check_duplicate_color(t_cube *cube, int id, char *format)
{
	if (id == F && cube->id->f_bool == true)
	{
		free(format);
		ft_error_parsing(cube, "duplicate texture ID : 'F' found.");
	}
	else if (id == C && cube->id->c_bool == true)
	{
		free(format);
		ft_error_parsing(cube, "duplicate texture ID : 'C' found.");
	}
}

void	check_duplicate_path(t_cube *cube, int id, char *path)
{
	if (id == NO && cube->id->no_bool == true)
	{
		free(path);
		ft_error_parsing(cube, "duplicate texture ID : 'NO' found.");
	}
	else if (id == SO && cube->id->so_bool == true)
	{
		free(path);
		ft_error_parsing(cube, "duplicate texture ID : 'NO' found.");
	}
	else if (id == WE && cube->id->we_bool == true)
	{
		free(path);
		ft_error_parsing(cube, "duplicate texture ID : 'NO' found.");
	}
	else if (id == EA && cube->id->ea_bool == true)
	{
		free(path);
		ft_error_parsing(cube, "duplicate texture ID : 'NO' found.");
	}
}

void	change_id_path_bool(t_cube *cube, int id, char *path)
{
	if (id == NO)
	{
		check_duplicate_path(cube, id, path);
		cube->id->no_bool = true;
	}
	else if (id == SO)
	{
		check_duplicate_path(cube, id, path);
		cube->id->so_bool = true;
	}
	else if (id == WE)
	{
		check_duplicate_path(cube, id, path);
		cube->id->we_bool = true;
	}
	else if (id == EA)
	{
		check_duplicate_path(cube, id, path);
		cube->id->ea_bool = true;
	}
}

void	check_path(t_cube *cube, int id, int *i, int *j)
{
	char	*path;
	int		fd;

	path = ft_substr(cube->map->grid[*i], (*j),
			(ft_strlen(cube->map->grid[*i]) - (*j)));
	fd = open(path, O_RDONLY);
	// void(id);
	// if (fd < 0)
	// {
	// 	free(path);
	// 	ft_error_parsing(cube, "cannot find texture's path.\n");
	// }
	change_id_path_bool(cube, id, path);
	free(path);
}
