/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:12:21 by skock             #+#    #+#             */
/*   Updated: 2025/06/27 16:54:27 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	init_colors(t_cube *cube)
{
	cube->color_f->r_color = 0;
	cube->color_f->g_color = 0;
	cube->color_f->b_color = 0;
	cube->color_c->r_color = 0;
	cube->color_c->g_color = 0;
	cube->color_c->b_color = 0;
}

void	init_struct(t_cube *cube, char **av)
{
	cube->id = malloc(sizeof(t_id));
	if (!cube->id)
		exit(1);
	cube->color_f = malloc(sizeof(t_color));
	if (!cube->color_f)
		exit(1);
	cube->color_c = malloc(sizeof(t_color));
	if (!cube->color_c)
		exit(1);
	init_colors(cube);
	cube->av = av;
	cube->file_path = av[1];
	cube->id->no_bool = false;
	cube->id->so_bool = false;
	cube->id->we_bool = false;
	cube->id->ea_bool = false;
	cube->id->f_bool = false;
	cube->id->c_bool = false;
}
