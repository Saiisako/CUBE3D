/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:42:12 by skock             #+#    #+#             */
/*   Updated: 2025/06/27 18:18:50 by skock            ###   ########.fr       */
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

typedef enum s_enum
{
	NO = 1,
	SO,
	WE,
	EA,
	F,
	C,
}		t_enum;

typedef struct s_color
{
	int	r_color;
	int	g_color;
	int	b_color;
}	t_color;

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
	t_color	*color_f;
	t_color	*color_c;
}			t_cube;

///////////////// FUNCTIONS /////////////////

		////////// PARSING //////////

t_enum	verif_id_key(char current, char next);
int		ft_atoi_rgb(const char *str);
int		ft_is_upper_alpha(int c);
int		check_boolean(t_cube *cube);
void	is_cub(char	*file_path);
void	init_colors(t_cube *cube);
void	ft_error_fd(t_cube *cube);
void	ft_error_parsing(t_cube *cube, const char *str);
void	parsing(t_cube *cube);
void	read_map2(const char *file_path, t_cube *cube);
void	read_map(const char *file_path, t_cube *cube);
void	free_array(char **array);
void	free_all(t_cube *cube);
void	init_struct(t_cube *cube, char **av);
void	check_path(t_cube *cube, int id, int *i, int *j);
void	change_id_path_bool(t_cube *cube, int id, char *path);;
void	check_duplicate_id(t_cube *cube, int id, char *path);
void	check_args(t_cube *cube, int id, int *i, int *j);
void	check_id(t_cube *cube);
void	change_id_color_bool(t_cube *cube, int id, char *format);
void	verif_rgb(t_cube *cube, char *format, char **rgb);
void	check_format(t_cube *cube, char *format, int id);
void	check_colors(t_cube *cube, int id, int *i, int *j);
void	check_duplicate_color(t_cube *cube, int id, char *format);

		////////// GAME //////////

void	graphic(t_cube *cube);

#endif