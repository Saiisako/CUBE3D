/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:09:26 by skock             #+#    #+#             */
/*   Updated: 2025/06/26 18:50:26 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	ft_error_fd(void)
{
	ft_printf("Error: Enable to open the file.\n");
	exit(1);
}

void	ft_error_parsing(t_cube *cube, const char *str)
{
	if (cube && cube->map && cube->map->grid)
		free_array(cube->map->grid);
	if (cube && cube->map)
		free(cube->map);
	if (cube)
		free(cube);
	ft_printf("Error : %s\n", str);
	exit(1);
}
