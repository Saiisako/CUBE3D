/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:42:12 by skock             #+#    #+#             */
/*   Updated: 2025/07/02 10:43:16 by skock            ###   ########.fr       */
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
	int		grid_length;
	int		grid_height;
}			t_map;

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
}			t_cube;

///////////////// FUNCTIONS /////////////////

		////////// PARSING //////////

void	check_duplicate_color(t_cube *cube, int id, char *format);
void	change_id_color_bool(t_cube *cube, int id, char *format);
void	check_bottom_map(t_cube *cube, char **tab, int i, int j);
void	check_duplicate_path(t_cube *cube, int id, char *path);
void	change_id_path_bool(t_cube *cube, int id, char *path);
void	check_colors(t_cube *cube, int id, int *i, int *j);
void	verif_rgb(t_cube *cube, char *format, char **rgb);
void	check_args(t_cube *cube, int id, int *i, int *j);
void	check_right_map(t_cube *cube, char **tab, int i);
void	check_format(t_cube *cube, char *format, int id);
void	check_left_map(t_cube *cube, char **tab, int i);
void	ft_error_parsing(t_cube *cube, const char *str);
void	read_map2(const char *file_path, t_cube *cube);
void	check_top_map(t_cube *cube, char **tab, int i);
void	read_map(const char *file_path, t_cube *cube);
void	copy_map(t_cube *cube, int start, int length);
void	verif_map(t_cube *cube);
void	is_cub(char	*file_path);
void	init_colors(t_cube *cube);
void	ft_error_fd(t_cube *cube);
void	parsing(t_cube *cube);
void	free_array(char **array);
void	free_all(t_cube *cube);
void	init_struct(t_cube *cube, char **av);
void	check_path(t_cube *cube, int id, int *i, int *j);
void	check_map(t_cube *cube, int i);
void	ft_error_parsing_map(t_cube *cube, const char *str);
void	print_map(char **map);
void	is_enclosed_map(t_cube *cube, int i, int j);
void	check_x(t_cube *cube);
void	ft_error_parsing_empty_map(t_cube *cube, const char *str);
int		get_longest_line(char **map, int i);
int		update_start(t_cube *cube, int start);
int		update_height(t_cube *cube, int start);
int		ft_atoi_rgb(const char *str);
int		ft_is_upper_alpha(int c);
int		check_boolean(t_cube *cube);
int		check_id(t_cube *cube);
int		is_valid_start(char *line);
int		is_valid_char(t_cube *cube, char c);
int		is_border(t_cube *cube, int i, int j);
char	*ft_strdup_set(const char *line, int end);
t_enum	verif_id(char current, char next);
void	error_comma(t_cube *cube, char *format);

		////////// GAME //////////

void	graphic(t_cube *cube);

#endif