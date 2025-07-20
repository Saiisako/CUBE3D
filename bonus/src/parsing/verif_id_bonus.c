/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_id_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:00:01 by skock             #+#    #+#             */
/*   Updated: 2025/07/20 13:23:41 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube_bonus.h"

static int	check_boolean(t_cube *cube)
{
	if (cube->id->no_bool && cube->id->so_bool && cube->id->we_bool
		&& cube->id->ea_bool && cube->id->f_bool && cube->id->c_bool)
		return (0);
	else
		return (1);
}

static void	check_args(t_cube *cube, int id, int *i, int *j)
{
	if (!id)
		ft_error_parsing(cube, "identification incorrect.");
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

static t_enum	verif_id(char current, char next)
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

int	is_line_empty_or_whitespace(char *line)
{
	int	k;

	k = 0;
	while (line[k])
	{
		if (!ft_iswhitespace(line[k]))
			return (0);
		k++;
	}
	return (1);
}

int	check_id(t_cube *cube)
{
	int	i;
	int	j;
	int	id;

	i = 0;
	while (cube->map->grid[i])
	{
		if (is_line_empty_or_whitespace(cube->map->grid[i]))
		{
			i++;
			continue ;
		}
		j = 0;
		while (ft_iswhitespace(cube->map->grid[i][j]))
			j++;
		if (!ft_is_upper_alpha(cube->map->grid[i][j]))
			ft_error_parsing(cube, "identification incorrect.");
		id = verif_id(cube->map->grid[i][j], cube->map->grid[i][j + 1]);
		check_args(cube, id, &i, &j);
		i++;
		if (!check_boolean(cube))
			break ;
	}
	return (i);
}
