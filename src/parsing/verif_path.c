/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:57:53 by skock             #+#    #+#             */
/*   Updated: 2025/07/19 16:08:00 by naankour         ###   ########.fr       */
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
static void	is_xpm(t_cube *cube, char	*file_path)
{
	int	i;

	i = 0;
	while (file_path[i] != '\0')
		i++;
	if (file_path[i - 1] == 'm' && file_path[i - 2] == 'p'
		&& file_path[i - 3] == 'x' && file_path[i - 4] == '.')
		return ;
	else
		ft_error_parsing(cube, "texture's path must be '.xpm'.");
}
void	check_path(t_cube *cube, int id, int *i, int *j)
{
	char	*path;
	int		fd;

	path = ft_substr(cube->map->grid[*i], (*j),
	(ft_strlen_space(cube->map->grid[*i]) - (*j)));
	printf("la ligne complete %zu\n", ft_strlen(cube->map->grid[*i]));
	printf("le path %zu\n", ft_strlen(path));
	is_xpm(cube, path);
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
