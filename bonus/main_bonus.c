/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:41:54 by skock             #+#    #+#             */
/*   Updated: 2025/07/20 13:06:52 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

int	main(int ac, char **av)
{
	t_cube	*cube;

	cube = malloc(sizeof(t_cube));
	if (ac == 2)
	{
		init_struct(cube, av);
		parsing(cube);
		graphic(cube);
	}
	else
	{
		printf("Error: You must provide ONE map.\n");
		free(cube);
	}
	return (0);
}
