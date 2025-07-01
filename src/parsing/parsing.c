/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:15:24 by skock             #+#    #+#             */
/*   Updated: 2025/07/01 11:56:57 by skock            ###   ########.fr       */
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

char	*ft_strdup_set(const char *line, int end)
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

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
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
	int	temp;
	int	l;

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
	copy_map(cube, temp, l);
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
