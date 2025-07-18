/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:47:16 by skock             #+#    #+#             */
/*   Updated: 2025/07/18 16:33:22 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

static void	is_enclosed_map(t_cube *cube, int i, int j)
{
	char	**tab;

	tab = cube->map_cpy->grid;
	if (tab[i][j] == 'X' && ((tab[i][j + 1] != 'X') && (tab[i][j + 1] != '1')))
		ft_error_parsing_map(cube, "map not closed.");
	if (tab[i][j] == 'X' && ((tab[i][j - 1] != 'X') && (tab[i][j - 1] != '1')))
		ft_error_parsing_map(cube, "map not closed.");
	if (tab[i][j] == 'X' && (tab[i + 1][j] != 'X' && tab[i + 1][j] != '1'))
		ft_error_parsing_map(cube, "map not closed.");
	if (tab[i][j] == 'X' && (tab[i - 1][j] != 'X' && tab[i - 1][j] != '1'))
		ft_error_parsing_map(cube, "map not closed.");
}

static int	is_border(t_cube *cube, int i, int j)
{
	if ((i >= 0 && i <= cube->map_cpy->grid_height) && (j == 0))
		return (1);
	else if ((i >= 0 && i <= cube->map_cpy->grid_height)
		&& (j == (cube->map_cpy->grid_length - 1)))
		return (1);
	else if ((i == 0) && (j >= 0 && j <= cube->map_cpy->grid_length))
		return (1);
	else if ((i == (cube->map_cpy->grid_height - 1))
		&& (j >= 0 && j <= (cube->map_cpy->grid_length - 1)))
		return (1);
	else
		return (0);
}

void	check_x(t_cube *cube)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	tab = cube->map_cpy->grid;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (is_border(cube, i, j))
			{
				j++;
				continue ;
			}
			is_enclosed_map(cube, i, j);
			j++;
		}
		i++;
	}
}
