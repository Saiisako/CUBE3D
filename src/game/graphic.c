/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:19:39 by skock             #+#    #+#             */
/*   Updated: 2025/07/15 18:33:04 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int	render(t_cube *cube)
{
	raycasting(cube);
	return (0);
}
void	graphic(t_cube *cube)
{
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	init_game(cube);
	find_player_position(cube);
	init_player_position(cube);
	raycasting(cube);
	mlx_loop_hook(cube->mlx, render, cube);
	mlx_loop(cube->mlx);
	return ;
}
