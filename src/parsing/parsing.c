/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:15:24 by skock             #+#    #+#             */
/*   Updated: 2025/06/27 11:48:11 by skock            ###   ########.fr       */
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

t_enum	verif_id_key(char current, char next)
{
	if (current == 'N' && next == 'O')
		return (NO);
	else if (current == 'S' && next == 'O')
		return (SO);
	else if (current == 'W' && next == 'E')
		return (WE);
	else if (current == 'E' && next == 'A')
		return (EA);
	else if (current == 'F' && ft_iswhitespace(next))
		return (F);
	else if (current == 'C' && ft_iswhitespace(next))
		return (C);
	else
		return (0);
}
void	check_path(t_cube *cube, int id, int *i, int *j)
{
	char *path;
	(void)id;
	int	fd;
	
	path = ft_substr(cube->map->grid[*i], (*j), (ft_strlen(cube->map->grid[*i]) - (*j)));
	fd = open(path, O_RDONLY);
	// if (fd < 0)
	// 	ft_error_parsing(cube, "error: cannot find texture's path\n");
	(*i)++;
}

void	check_args(t_cube *cube, int id, int *i, int *j)
{
	if (!id)
		ft_error_parsing(cube, "error: identification incorrect\n");
	if (id == NO || id == SO || id == WE || id == EA)
	{
		(*j) += 2;
		while (ft_iswhitespace(cube->map->grid[*i][*j]))
			(*j)++;
		check_path(cube, id, i, j);
	}
	// else if (id == F || id == C)
	// {
	// 	(*j)++;
	// 	while (ft_iswhitespace(cube->map->grid[*i][*j]))
	// 		(*j)++;
	// 	// check_colors();

	// }
	(*j)++;
	
}

void	check_id(t_cube *cube)
{
	int	i;
	int	j;
	int id;
	
	j = 0;
	i = 0;
	while (cube->map->grid[i])
	{
		printf("%s\n", cube->map->grid[i]);
		while (cube->map->grid[i][j])
		{
			while (ft_iswhitespace(cube->map->grid[i][j]))
				j++;
			if (!ft_is_upper_alpha(cube->map->grid[i][j]))
			{
				printf("char verified = %c\n",cube->map->grid[i][j]);
				ft_error_parsing(cube, "error: identification incorrect\n");
			}
			else
			{
				id = verif_id_key(cube->map->grid[i][j], cube->map->grid[i][j + 1]);
				check_args(cube, id, &i, &j);
			}
			i++;
		}
	}
}

void	parsing(t_cube *cube)
{
	read_map(cube->file_path, cube);
	is_cub(cube->file_path);
	
	printf("\n");
	printf("\n");
	printf("\n");
	check_id(cube);
	
}
