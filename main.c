/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:41:54 by skock             #+#    #+#             */
/*   Updated: 2025/07/07 13:23:15 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	t_cube	*cube;

	cube = malloc(sizeof(t_cube));
	if (ac == 2)
	{
		init_struct(cube, av);
		parsing(cube);
		find_player_position(cube);
		init_player_position(cube);
		graphic(cube);
		free_all(cube);
	}
	else
		free(cube);
	// printf("here\n");
	return (0);
}
