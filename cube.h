/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:42:12 by skock             #+#    #+#             */
/*   Updated: 2025/07/07 13:25:00 by naankour         ###   ########.fr       */
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
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
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
	int		grid_length;
	int		grid_height;
}			t_map;

typedef struct s_player
{
	char	dir;
	double	player_x;
	double	player_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_cube
{
	char	**av;
	char	*file_path;
	t_id	*id;
	t_map	*map;
	t_map	*map_cpy;
	t_color	*color_f;
	t_color	*color_c;
	int		count;
	t_player	*player;
}			t_cube;

// dir_x et dir_y: vecteur direction du joueur (vers la ou il regarde)
// si le joueur regarde vers N dir_x = 0 dir_y = -1
// si le joueur regarde vers S dir_x = 0 dir_y = +1
// si le joueur regarde vers E dir_x = +1 dir_y = 0
// si le joueur regarde vers W dir_x = -1 dir_y = 0

// plane_x et plane_y :champs de vision du joueur, perpendiculaire a dir, represente le plan de la camera
// vecteur perpendiculaire a (x, y) est (-y, x) quon doit multiplier par FOV (environ 0.66 car un champs de vision reliste cest 66°) donc;
// si le joueur regarde vers N (plane_x = 1 plane_y = 0) * 0.66 = (plane_x = 0.66 plane_y = 0)
// si le joueur regarde vers S (plane_x = -1 plane_y = 0) * 0.66 = (plane_x = -0.66 plane_y = 0)
// si le joueur regarde vers E (plane_x = 0 plane_y = 1) * 0.66 = (plane_x = 0 plane_y = 0.66)
// si le joueur regarde vers W (plane_x = 0 plane_y = -1) * 0.66 = (plane_x = 0 plane_y = -0.66)
// finalement :
// plane_x = -dir_y * 0.66;
// plane_y = dir_x * 0.66;

// pour initialiser la position du joueur avec son vecteur dir et plane, il faut pouvoir recuperer  N S E W et la structure player
// Pour ca au niveau du parsing il faut recuperer la position du joueur avec ses coordonnees + l orientation donc stocker N S E ou W donc une variable

///////////////// FUNCTIONS /////////////////

		////////// PARSING //////////

void	parsing(t_cube *cube);
void	read_map(const char *file_path, t_cube *cube);
void	init_struct(t_cube *cube, char **av);
int		check_id(t_cube *cube);
void	verif_map(t_cube *cube);
void	check_path(t_cube *cube, int id, int *i, int *j);
void	check_colors(t_cube *cube, int id, int *i, int *j);
void	check_duplicate_color(t_cube *cube, int id, char *format);
void	change_id_color_bool(t_cube *cube, int id, char *format);
void	check_x(t_cube *cube);
char	*ft_strdup_set(const char *line, int end);
void	check_comma(t_cube *cube, char *format);
void	copy_map(t_cube *cube, int start, int length);
void	print_map(char **map);

//UTILS
int		ft_is_upper_alpha(int c);
int		ft_atoi_rgb(const char *str);
int		is_valid_char(t_cube *cube, char c);
int		is_valid_start(char *line);
int		update_start(t_cube *cube, int start);
int		update_height(t_cube *cube, int start);
int		get_longest_line(char **map, int i);

// FREE + ERROR
void	free_all(t_cube *cube);
void	free_array(char **array);
void	ft_error_fd(t_cube *cube);
void	ft_error_parsing(t_cube *cube, const char *str);
void	ft_error_parsing_map(t_cube *cube, const char *str);
void	ft_error_parsing_empty_map(t_cube *cube, const char *str);

		////////// GAME //////////
void	graphic(t_cube *cube);

// INIT PLAYER
void	find_player_position(t_cube *cube);
void	init_player_position(t_cube *cube);
#endif