/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:12:21 by skock             #+#    #+#             */
/*   Updated: 2025/06/26 19:23:39 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	init_struct(t_cube *cube, char **av)
{
	cube->id = malloc(sizeof(t_id));
	cube->av = av;
	cube->file_path = av[1];
	cube->id->no_bool = false;
	cube->id->so_bool = false;
	cube->id->we_bool = false;
	cube->id->ea_bool = false;
	cube->id->f_bool = false;
	cube->id->c_bool = false;
}
