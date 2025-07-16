/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:42:12 by skock             #+#    #+#             */
/*   Updated: 2025/07/16 18:11:35 by naankour         ###   ########.fr       */
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
# include <math.h>

#define WIN_WIDTH 720
#define WIN_HEIGHT 400
#define VERTICAL 0
#define HORIZONTAL 1
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3
#define TEXTURE_SIZE 64


typedef enum s_enum
{
	NO = 1,
	SO,
	EA,
	WE,
	F,
	C,
}		t_enum;

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

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

typedef struct s_ray
{
	double	camerax;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
	double	line_height;
	double	draw_start;
	double	draw_end;
	double	wall_x;
	double	tex_x;
}			t_ray;

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

typedef struct s_texture
{

	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
}					t_texture;

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
	t_ray		*ray;
	char		**path;
	t_image		*img;
	void		*mlx;
	void		*win;
	t_texture	*texture;
	int			**texture_img;
}			t_cube;


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
void	init_game(t_cube *cube);
int		raycasting(t_cube *cube);

// INIT PLAYER
void	find_player_position(t_cube *cube);
void	init_player_position(t_cube *cube);
#endif