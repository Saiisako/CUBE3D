/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:13:52 by skock             #+#    #+#             */
/*   Updated: 2025/07/02 12:49:30 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	copy_map(t_cube *cube, int start, int length)
{
	int	j;
	int	height;

	j = 0;
	start = update_start(cube, start);
	height = update_height(cube, start);
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

static void	read_map2(const char *file_path, t_cube *cube)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_error_fd(cube);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			cube->map->grid[i] = ft_substr(line, 0, (ft_strlen(line) - 1));
		else
			cube->map->grid[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	cube->map->grid[i] = NULL;
	close (fd);
}

void	read_map(const char *file_path, t_cube *cube)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_error_fd(cube);
	i = 0;
	line = get_next_line(fd);
	if (line == NULL)
		ft_error_parsing_empty_map(cube, "map is empty");
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	cube->map = malloc(sizeof(t_map));
	cube->map->grid_height = i;
	cube->map->grid = malloc(sizeof(char *) * (i + 1));
	if (!cube->map->grid)
		return ;
	read_map2(file_path, cube);
}
