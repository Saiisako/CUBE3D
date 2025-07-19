/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:57:53 by skock             #+#    #+#             */
/*   Updated: 2025/07/19 18:10:47 by skock            ###   ########.fr       */
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

static void	check_duplicate_path(t_cube *cube, int id, char *path)
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

static void	change_id_path_bool(t_cube *cube, int id, char *path)
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

void	stock_path(t_cube *cube, int id, char *path)
{
	if (id == NO)
	{
		free(cube->path[0]);
		cube->path[NORTH] = ft_strdup(path);
	}
	else if (id == SO)
	{
		free(cube->path[1]);
		cube->path[SOUTH] = ft_strdup(path);
	}
	else if (id == EA)
	{
		free(cube->path[2]);
		cube->path[EAST] = ft_strdup(path);
	}
	else if (id == WE)
	{
		free(cube->path[3]);
		cube->path[WEST] = ft_strdup(path);
	}
}

void	process_path(t_cube *cube, char **str)
{
	char	*new_str;
	int i;
	
	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == ' ' || (*str)[i] == '\n' || (*str)[i] == '\t')
			break;
		i++;
	}
	new_str = ft_substr(*str, 0, i);
	if (ft_strcmp(new_str + (ft_strlen(new_str) - 4), ".xpm") != 0)
		ft_error_parsing(cube, "Need .xpm extension for a texture");
	free(*str);
	*str = new_str;
}

void	verif_path(t_cube *cube, char **str)
{
	int i;

	i = 0;
	if (ft_strlen((*str)) < 4)
	{
		free((*str));
		ft_error_parsing(cube, "Need .xpm extension for a texture");
	}
	while ((*str)[i] && !ft_iswhitespace((*str)[i]))
		i++;
	if (!(*str)[i])
		process_path(cube, str);
	else
	{
		while (ft_iswhitespace((*str)[i]))
			i++;
		if (!(*str)[i])
			process_path(cube, str);
		else
		{
			free((*str));
			ft_error_parsing(cube, "Cannot have 2 arguments as texture file");
		}
	}
}

void	check_path(t_cube *cube, int id, int *i, int *j)
{
	char	*path;
	int		fd;

	path = ft_substr(cube->map->grid[*i], (*j),
	(ft_strlen(cube->map->grid[*i]) - (*j)));
	verif_path(cube, &path);
	fd = open(path, O_RDONLY);
	stock_path(cube, id, path);
	if (fd < 0)
	{
		free(path);
		ft_error_parsing(cube, "cannot find texture's path.");
	}
	change_id_path_bool(cube, id, path);
	free(path);
}
