/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:15:24 by skock             #+#    #+#             */
/*   Updated: 2025/06/26 19:37:53 by skock            ###   ########.fr       */
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
		ft_error_parsing(NULL, "Invalid file. Extension must be '.cub'");
}

int	check_boolean(t_id *id)
{
	if (id->no_bool && id->so_bool && id->we_bool && id->ea_bool
			&& id->f_bool && id->c_bool)
		return (0);
	else
		return (1);
}

int	ft_is_upper_alpha(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

void	check_id(t_cube *cube)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (cube->map->grid[i])
	{
		while (cube->map->grid[i][j])
		{
			while (!ft_iswhitespace(cube->map->grid[i][j]) && ft_is_upper_alpha(cube->map->grid[i][j]))
			{
				printf("first char encounter : %c\n", cube->map->grid[i][j]);
				j++;
			}
			// while (check_boolean(cube->id))
			// {
			// 	if (ft_strncmp())
			// }
			j++;
		}
		i++;
	}
}

void	parsing(t_cube *cube)
{
	read_map(cube->file_path, cube);
	is_cub(cube->file_path);
	
	for (size_t i = 0; cube->map->grid[i]; i++)
		printf("%s\n", cube->map->grid[i]);
	check_id(cube);
	
}
