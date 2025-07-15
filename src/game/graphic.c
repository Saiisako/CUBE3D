/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:19:39 by skock             #+#    #+#             */
/*   Updated: 2025/07/15 14:48:06 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	graphic(t_cube *cube)
{
	init_game(cube);
	find_player_position(cube);
	init_player_position(cube);
	raycasting(cube);
	return ;
}
