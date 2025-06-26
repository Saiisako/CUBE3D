/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:42:12 by skock             #+#    #+#             */
/*   Updated: 2025/06/26 19:04:02 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "library/gnl/get_next_line.h"
# include "library/libft/libft.h"
# include "library/printf/ft_printf.h"
# include <stdbool.h>

typedef struct s_id
{
	bool	no_bool;
	bool	so_bool;
	bool	we_bool;
	bool	ea_bool;
	bool	f_bool;
	bool	c_bool;
}			t_id;

typedef struct s_map
{
	char	**grid;
	int		grid_lenght;
	int		grid_height;
}			t_map;

typedef struct s_cube
{
	char	**av;
	char	*file_path;
	t_id	*id;
	t_map	*map;
}			t_cube;

///////////////// FUNCTIONS /////////////////

		////////// PARSING //////////

void	ft_error_fd(void);
void	ft_error_parsing(t_cube *cube, const char *str);
void	parsing(t_cube *cube);
void	read_map2(const char *file_path, t_cube *cube);
void	read_map(const char *file_path, t_cube *cube);
void	free_array(char **array);
void	free_all(t_cube *cube);
void	init_struct(t_cube *cube, char **av);

		////////// GAME //////////

void	graphic(t_cube *cube);

#endif