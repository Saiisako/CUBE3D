/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:13:52 by skock             #+#    #+#             */
/*   Updated: 2025/06/27 17:09:49 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	read_map2(const char *file_path, t_cube *cube)
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
