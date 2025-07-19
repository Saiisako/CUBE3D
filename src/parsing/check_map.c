/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 08:39:29 by skock             #+#    #+#             */
/*   Updated: 2025/07/19 13:52:40 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

static void	check_bottom_map(t_cube *cube, char **tab, int i, int j)
{
	while (tab[i])
		i++;
	--i;
	while (tab[i][j])
	{
		if (tab[i][j] == '1')
		{
			j++;
			continue ;
		}
		if (tab[i][j] != 'X' && tab[i][j] != '1')
			ft_error_parsing_map(cube, "map is not closed");
		if (tab[i - 1][j] != 'X' && tab[i - 1][j] != '1')
			ft_error_parsing_map(cube, "map is not closed");
		j++;
	}
}

static void	check_top_map(t_cube *cube, char **tab, int i)
{
	while (tab[0][i])
	{
		if (tab[0][i] == '1')
		{
			i++;
			continue ;
		}
		if (tab[0][i] != 'X' && tab[0][i] != '1')
			ft_error_parsing_map(cube, "map is not closed");
		if (tab[1][i] != 'X' && tab[1][i] != '1')
			ft_error_parsing_map(cube, "map is not closed");
		i++;
	}
}

static void	check_right_map(t_cube *cube, char **tab, int i)
{
	while (tab[i])
	{
		if (tab[i][cube->map_cpy->grid_length - 1] == '1')
		{
			i++;
			continue ;
		}
		if (tab[i][cube->map_cpy->grid_length - 1] != 'X'
			&& tab[i][cube->map_cpy->grid_length - 1] != '1')
			ft_error_parsing_map(cube, "map is not closed");
		if (tab[i][cube->map_cpy->grid_length - 2] != 'X'
			&& tab[i][cube->map_cpy->grid_length - 2] != '1')
			ft_error_parsing_map(cube, "map is not closed");
		i++;
	}
}

static void	check_left_map(t_cube *cube, char **tab, int i)
{
	while (tab[i])
	{
		if (tab[i][0] == '1')
		{
			i++;
			continue ;
		}
		if (tab[i][0] != 'X' && tab[i][0] != '1')
			ft_error_parsing_map(cube, "map is not closed.");
		if (tab[i][1] != 'X' && tab[i][1] != '1')
			ft_error_parsing_map(cube, "map is not closed.");
		i++;
	}
}

void	verif_map(t_cube *cube)
{
	check_left_map(cube, cube->map_cpy->grid, 0);
	check_right_map(cube, cube->map_cpy->grid, 0);
	check_top_map(cube, cube->map_cpy->grid, 0);
	check_bottom_map(cube, cube->map_cpy->grid, 0, 0);
	check_x(cube);
}
