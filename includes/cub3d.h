/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:12:22 by svidal            #+#    #+#             */
/*   Updated: 2023/12/21 16:39:52 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <X11/keysym.h>
# include <X11/X.h>

# include "colors.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/ft_printf.h"
# include "../minilibx-linux/mlx.h"

// GAME IMG KEYS


// GAME KEYWORDS
# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define A 97
# define D 100
# define S 115
# define W 119
# define SPEED 0.01
# define ROTATE 0.01

# define WIN_TITLE "cub3D"

# define PLAYER_N 'N'
# define PLAYER_S 'S'
# define PLAYER_E 'E'
# define PLAYER_W 'W'
# define WALL '1'
# define FLOOR '0'

# define WIN_WIDTH 1080 //largeur
# define WIN_HEIGHT 720 //hauteur
# define TEXTURE_SIZE 64
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define MINI_TILESIZE 16

// STRUCTURES

typedef struct s_map
{
	char		**map;
	char		**map_cpy;
	char		**data;
	char		*path;
	int			map_width;
	int			map_height;
	int			nb_lines;
	int			map_lines;
	int			data_lines;
	int			nb_columns;
}	t_map;


typedef struct s_img
{
	void		*main_img;
	//void	*floor;
	//void	*wall;
	char	*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_infos
{
	//char	player;
	//char	wall;
	//char	floor;
}	t_infos;

typedef struct s_pst //position de depart du joueur
{
	double			first_pst_x; // x = ligne
	double			first_pst_y; // y = colonne
}	t_pst;

typedef struct s_player
{
	char	dir;
	double	pst_x; // position du joueur x
	double	pst_y;
	double	dir_x; // vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double	dir_y;
	double	wall_dist;
	double	plan_x; // vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double	plan_y;
	int				has_moved; // ?
	int				move_x;
	int				move_y;
	int				rotate;
	int			nb_player;
}	t_player;

typedef struct s_txtr
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				tex_x;
	int				tex_y;
	int				index;
	double			step;
	double			pos;
}	t_txtr;

typedef struct s_ray
{
	int	xxx; //permet de parcourir tous les rayons
	int	map_x; //coordonée x du carré dans lequel est positionne le joueur
	int	map_y;
	int	step_x; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int	step_y; //-1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int	side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	int	line_height; //hauteur de la ligne a dessiner
	int	draw_start; //position de debut ou il faut dessiner
	int	draw_end; //position de fin ou il faut dessiner
	double	ray_dir_x; // calcul de direction x du rayon
	double	ray_dir_y; //calcul de direction y du rayon
	double	camera_x; // point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	double	side_dist_x; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double	side_dist_y; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double	delta_dist_x; //distance que rayon parcours entre chaque point d'intersection vertical
	double	delta_dist_y; //distance que le rayon parcours entre chaque point d'intersection horizontal
	double	wall_dist;
	double	wall_x;
}	t_ray;


typedef struct s_general
{
	void		*mlx_ptr;
	void		*win_ptr;
	int				win_width;
	int				win_height;
	int				**txtr_pixels;
	int				**txtr;
	t_map		map_ptr;
	t_img		img_ptr;
	t_infos		inf_ptr;
	t_pst		pst_ptr;
	t_player	player_ptr;
	t_txtr		txtr_ptr;
	t_ray		ray_ptr;
}	t_general;

// PROTOTYPES

/* errors */
void	ft_error_msg(char *str, t_general *general);
void	ft_map_ext_error(const char *filename, t_general *general);
void	ft_empty_map_error(t_general *general);
void	ft_invalid_char_error(t_general *general);
void	ft_wrong_nb_player(t_general *general);
int		ft_check_wall_error(t_general *general, int i, int j);
void	ft_map_wall_error(t_general *general);
void	ft_all_errors(t_general *general);
int		ft_check_file(const char *filename, t_general *general);
bool	ft_ignore_empty_and_config(char *line);

/* free and exit */
void	ft_free_map(char **tab, t_general *general);
void	ft_free_img(t_general *general);
int		ft_exit_game(t_general *general);

/* init */
void	ft_init_s_map(t_map *map_ptr);
void	ft_init_s_img(t_img *img_ptr);
void	ft_init_s_pst(t_pst *pst_ptr);
void	ft_init_s_player(t_player *player_ptr);
void	ft_init_s_txtr(t_txtr *txtr_ptr);
void	ft_init_s_ray(t_ray *ray_ptr);
void	ft_init_s_gen(t_general *general);
void	ft_pst_player(t_general *general);
void	ft_nb_players(t_general *general);

/* map */
void	ft_split_map(char *filename, t_general *gen);
void	ft_split_map_2(char *line, int fd, t_general *gen);
char	**ft_copy_map(char **map_cpy, t_general *gen);
void	ft_nb_lines(char *filename, t_general *gen);
int		ft_max_line_len(char **map);
void 	display_minimap(t_general *general);

/* mlx */
void	ft_mlx_win(t_general *general);

/* utils */
void	print_tab(char **tab);

/* raycasting */
void	raycasting(t_player *player, t_general *gen);

/* controls */
void	ft_handle_events(t_general *gen);


/* rajout externes */
void	set_image_pixel(t_img *image, int x, int y, int color);
void	render_images(t_general *gen);
int		render(t_general *gen);
void	update_texture_pixels(t_general *gen, t_txtr *tex, t_ray *ray, int x);
void	init_texture_pixels(t_general *gen);
void	raycasting(t_player *player, t_general *gen);
int		validate_move(t_general *gen, double new_x, double new_y);
void	player_direction(t_general *gen);
int		move_player(t_general *gen);
int		rotate_player(t_general *gen, double rot_dir);
void	init_ray(t_ray *ray);
void	init_texture_img(t_general *gen, t_img *image, char *path);
void	init_img(t_general *gen, t_img *image, int width, int height);
void	init_textures(t_general *gen);
int		get_file_gen(t_general *gen, char **data);
int		fill_color_textures(t_general *gen, t_txtr *tex, char *line, int j);
void	free_tab(void **tab);

#endif
