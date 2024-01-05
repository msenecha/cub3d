/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:17:35 by msenecha          #+#    #+#             */
/*   Updated: 2024/01/05 16:17:48 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <ctype.h>
# include <math.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx_linux/mlx.h"
# include "../minilibx_linux/mlx_int.h"
# include "colors.h"

/*----------MACROS-----------*/

//window
# define WIN_WIDTH 640
# define WIN_HEIGHT 480

//texture taille
# define TEX_SIZE 64

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

//mouv
# define MOVESPEED 0.0125
# define ROTSPEED 0.015

/*-----------ENUM---------*/

enum e_output
{
	ERROR = 2,
	BREAK = 3,
	CONTINUE = 4
};

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

/*---------- STRUCTURES ----------*/

//images
typedef struct s_image
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_image;

//textures
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
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texture;

//map
typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;
}	t_mapinfo;

//raycast
typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

//player
typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

//data
typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_mapinfo	mapinfo;
	char		**map;
	t_player	player;
	t_ray		ray;
	int			**texture_pixels;
	int			**textures;
	t_texture	texinfo;
}	t_data;

/*-------- FONCTIONS ----------*/

void	ft_init_image(t_data *data, t_image *image, int width, int height);
void	ft_init_txtr_img(t_data *data, t_image *image, char *path);
void	ft_init_mlx(t_data *data);
void	ft_init_txtr(t_data *data);
void	ft_init_txtr_inf(t_texture *textures);
void	ft_init_img(t_image *img);
void	ft_init_ray(t_ray *ray);
void	ft_init_data(t_data *data);
void	ft_parsing(char *path, t_data *data);
void	refresh_txtr(t_data *data, t_texture *tex, t_ray *ray, int x);
void	set_pixel_txtr(t_data *data);
void	my_put_pixel(t_image *image, int x, int y, int color);
void	handle_events(t_data *data);
void	set_player_orientation(t_data *data);
void	ft_free_tab(void **tab);
void	ft_exit(t_data *data, int code);
int		display_images(t_data *data);
int		ft_free(t_data *data);
int		error_msg(char *detail, char *str, int code);
int		error_msg_val(int detail, char *str, int code);
int		ft_color_txtr(t_data *data, t_texture *textures, char *line, int j);
int		ft_check_file(char *arg, bool cub);
int		ft_data(t_data *data, char **map);
int		ft_map_check(t_data *data, char **map_tab);
int		ft_map_sides(t_mapinfo *map, char **map_tab);
int		ft_creation_map(t_data *data, char **file, int i);
int		ft_txtr(t_data *data, t_texture *textures);
int		ft_space(char c);
int		rendering_frame(t_data *data);
int		raycastor(t_player *player, t_data *data);
int		player_movements(t_data *data);
int		is_valid_move(t_data *data, double new_x, double new_y);
int		player_rotation(t_data *data, double rot_dir);
int		error_msg(char *detail, char *str, int code);
int		error_msg_val(int detail, char *str, int code);
int		ft_exit_game(t_data *data);
size_t	ft_len_max(t_mapinfo *map, int i);

#endif
