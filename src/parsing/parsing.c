/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:15:24 by skock             #+#    #+#             */
/*   Updated: 2025/06/30 14:32:16 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	is_cub(char	*file_path)
{
	int	i;

	i = 0;
	while (file_path[i] != '\0')
		i++;
	if (i <= 4)
		ft_error_parsing(NULL, "Invalid file. Extension must be '.cub'.");
	if (file_path[i - 1] == 'b' && file_path[i - 2] == 'u'
		&& file_path[i - 3] == 'c' && file_path[i - 4] == '.')
		return ;
	else
		ft_error_parsing(NULL, "Invalid file. Extension must be '.cub'.");
}

int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'|| c == ' '
		|| c == 'W' || c == '\n')
		return (1);
	else
		return (0);
}

int	is_valid_start(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			return (1);
		i++;
	}
	return (0);
}

char *ft_strdup_set(const char *line, int end)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = malloc(sizeof(char) * end + 1);
	if (!new_line)
		exit(1);
	while (line[i])
	{
		if (line[i] == ' ')
			new_line[i] = 'X';
		else
			new_line[i] = line[i];
		i++;
	}
	while (i < end)
	{
		new_line[i] = 'X';
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

int	update_start(t_cube *cube, int start)
{
	while (cube->map->grid[start])
	{
		if (is_valid_start(cube->map->grid[start]))
			return (start);
		start++;
	}
	return (start);
}

void	copy_map(t_cube *cube, int start, int height, int length)
{
	int j;

	j = 0;
	start = update_start(cube, start);
	cube->map_cpy = malloc(sizeof(t_map));
	if (!cube->map_cpy)
		exit(1);
	cube->map_cpy->grid = malloc(sizeof(char *) * (height + 1));
	if (!cube->map_cpy->grid)
		exit(1);
	while (cube->map->grid[start])
	{
		cube->map_cpy->grid[j] = ft_strdup_set(cube->map->grid[start], length);
		start++;
		j++;
	}
	cube->map_cpy->grid[j] = NULL;
	cube->map_cpy->grid_height = height; 
	cube->map_cpy->grid_length = length;
}

int	get_longest_line(char **map, int i)
{
	int l;
	int tmp;

	l = 0;
	while (map[i])
	{
		tmp = ft_strlen(map[i]);
		if (tmp > l)
			l = tmp;
		i++;
	}
	return (l);
}

void	print_map(char **map)
{
	for (int i = 0; map[i]; i++)
		printf("%s\n", map[i]);
}

void	verif_map(t_cube *cube)
{
	int	i;
	char **line;

	line = cube->map_cpy->grid;
	i = 0;
	print_map(cube->map_cpy->grid);
	while (line[i])
	{
		if (line[i][0] != 'X' && line[i][0] != '1')
			ft_error_parsing_map(cube, "map is not closed");
		i++;
	}
}

// if (line[i][j] == 'X' && (line[i][j + 1] && ((line[i][j + 1] != 'X') && (line[i][j + 1] != '1'))))
// 	ft_error_parsing(cube, "map not closed.\n");
// if (line[i][j] == 'X' && (line[i][j - 1] && ((line[i][j - 1] != 'X') && (line[i][j - 1] != '1'))))
// 	ft_error_parsing(cube, "map not closed.\n");
// if (line[i][j] == 'X' && (line[i + 1][j] && (line[i + 1][j] != 'X' && line[i + 1][j] != '1')))
// 	ft_error_parsing(cube, "map not closed.\n");
// if (line[i][j] == 'X' && (line[i - 1][j] && (line[i - 1][j] != 'X' && line[i - 1][j] != '1')))
// 	ft_error_parsing(cube, "map not closed.\n");

void	check_map(t_cube *cube, int i)
{
	int	j;
	int temp;
	int l;

	temp = i;
	l = get_longest_line(cube->map->grid, i);
	while (cube->map->grid[i])
	{
		j = 0;
		while (cube->map->grid[i][j])
		{
			if (is_valid_char(cube->map->grid[i][j]))
				j++;
			else
				ft_error_parsing(cube, "invalid character on map.\n");
		}
		i++;
	}
	copy_map(cube, temp, i - temp, l);
	verif_map(cube);
}

void	parsing(t_cube *cube)
{
	int	i;

	read_map(cube->file_path, cube);
	is_cub(cube->file_path);
	i = check_id(cube);
	check_map(cube, i);
	
}

