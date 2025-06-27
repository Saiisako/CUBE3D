/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:00:01 by skock             #+#    #+#             */
/*   Updated: 2025/06/27 17:25:24 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int	check_boolean(t_id *id)
{
	if (id->no_bool && id->so_bool && id->we_bool && id->ea_bool
		&& id->f_bool && id->c_bool)
		return (0);
	else
		return (1);
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

void	check_duplicate_id(t_cube *cube, int id, char *path)
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

void	check_args(t_cube *cube, int id, int *i, int *j)
{
	if (!id)
		ft_error_parsing(cube, "identification incorrect.\n");
	if (id == NO || id == SO || id == WE || id == EA)
	{
		(*j) += 2;
		while (ft_iswhitespace(cube->map->grid[*i][*j]))
			(*j)++;
		check_path(cube, id, i, j);
	}
	else if (id == F || id == C)
	{
		(*j)++;
		while (ft_iswhitespace(cube->map->grid[*i][*j]))
			(*j)++;
		check_colors(cube, id, i, j);
	}
	while (cube->map->grid[*i][*j])
		(*j)++;
	(*j)--;
}

void	check_id(t_cube *cube)
{
	int	i;
	int	j;
	int	id;

	i = 0;
	while (cube->map->grid[i])
	{
		j = 0;
		while (cube->map->grid[i][j])
		{
			while (ft_iswhitespace(cube->map->grid[i][j]))
				j++;
			if (!ft_is_upper_alpha(cube->map->grid[i][j]))
				ft_error_parsing(cube, "identification incorrect.\n");
			else
			{
				id = verif_id_key(cube->map->grid[i][j],
						cube->map->grid[i][j + 1]);
				check_args(cube, id, &i, &j);
				j++;
			}
		}
		i++;
	}
}
