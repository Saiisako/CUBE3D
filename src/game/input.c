/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:01:17 by naankour          #+#    #+#             */
/*   Updated: 2025/07/18 17:01:17 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	quit_game(t_cube *cube)
{
	if (cube->quit)
		exit(1);
}

int	input(t_cube *cube)
{
	quit_game(cube);
	walk(cube);
	if (cube->rotate_left)
		rotate(cube, ROTATE_L);
	if (cube->rotate_right)
		rotate(cube, ROTATE_R);
	return (1);
}
