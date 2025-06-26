/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:41:54 by skock             #+#    #+#             */
/*   Updated: 2025/06/26 18:47:57 by skock            ###   ########.fr       */
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
		graphic(cube);
		free_all(cube);
	}
	else
		free(cube);
	return (0);
}
