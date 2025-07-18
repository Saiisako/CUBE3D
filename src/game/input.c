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

void	quit_game(t_cube *cube, int keycode)
{
	(void)cube;
	if (keycode == ESCAPE)
		exit(1);
}

int	move(int keycode, void *c)
{
	t_cube	*cube;

	cube = (t_cube *)c;
	quit_game(cube, keycode);
	walk(cube, keycode);
	rotate(cube, keycode);
	return (1);
}
