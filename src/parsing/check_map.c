/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 08:39:29 by skock             #+#    #+#             */
/*   Updated: 2025/07/02 10:04:47 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	is_enclosed_map(t_cube *cube, int i, int j)
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
	ft_error_parsing_map(cube, "map is correct\n");
}

void	verif_map(t_cube *cube)
{
	print_map(cube->map_cpy->grid);
	check_left_map(cube, cube->map_cpy->grid, 0);
	check_right_map(cube, cube->map_cpy->grid, 0);
	check_top_map(cube, cube->map_cpy->grid, 0);
	check_bottom_map(cube, cube->map_cpy->grid, 0, 0);
	check_x(cube);
}
