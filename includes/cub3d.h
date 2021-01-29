//
// Created by Daisey Patrica on 12/6/20.
//

#ifndef CUB3D_H
# define CUB3D_H

# define START_X 1700
# define START_Y 3
# define SQUARE xlm->width_square
# define X xlm->player.x
# define Y xlm->player.y
# define SPEED 0.05
# define VALID 0
# define NO_ARGS 1
# define MANY_ARGS 2
# define MAP_CUB_ERROR 3
# define SAVE_ERROR 4
# define MAP_OPEN_ERROR 5
# define MAP_TRASH_ERROR 6
# define MAP_TRASH_RESO_ERROR 7
# define DOUBLE_RESO_ERROR 8
# define RESO_NO_VALID_ERROR 9
# define DOUBLE_FRGB_ERROR 10
# define MAP_TRASH_FRGB_ERROR 11
# define FRGB_NO_VALID_ERROR 12
# define DOUBLE_CRGB_ERROR 13
# define MAP_TRASH_CRGB_ERROR 14
# define CRGB_NO_VALID_ERROR 15
# define DOUBLE_SPRITE_ERROR 16
# define MALLOC_SPRITE_ERROR 17
# define MAP_TRASH_SPRITE_ERROR 18
# define NO_SPRITE_ERROR 19
# define DOUBLE_NORTH_ERROR 20
# define MALLOC_NORTH_ERROR 21
# define MAP_TRASH_NORTH_ERROR 22
# define NO_NORTH_ERROR 23
# define DOUBLE_SOUTH_ERROR 24
# define MALLOC_SOUTH_ERROR 25
# define MAP_TRASH_SOUTH_ERROR 26
# define NO_SOUTH_ERROR 27
# define DOUBLE_WEST_ERROR 28
# define MALLOC_WEST_ERROR 29
# define MAP_TRASH_WEST_ERROR 30
# define NO_WEST_ERROR 31
# define DOUBLE_EAST_ERROR 32
# define MALLOC_EAST_ERROR 33
# define MAP_TRASH_EAST_ERROR 34
# define NO_EAST_ERROR 35
# define GNL_ERROR 36
# define NO_PARAM_ERROR 37
# define NO_MAP_ERROR 38
# define MALLOC_MAP_ERROR 39
# define T_ERROR 40
# define MAP_NO_VALID 41
# define DOUBLE_PLAYER_ERROR 42
# define NO_PLAYER_ERROR 43
# define MAP_EMPTY_LINE_ERROR 44
# define TEXTURE_ERROR 45
# define SPR_MALLOC_ERROR 46
//# define NO_ERROR
//# define SO_ERROR
//# define WE_ERROR
//# define EA_ERROR
//# define S_ERROR
//# define F_ERROR
//# define C_ERROR
# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"
# include "../minilibx_mms_20200219/mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_matrix
{
	int			x;
	int			y;
	int			step_x;
	int			step_y;
	int			draw_up;
	int			draw_down;
	int			line_len;
	int			side;
	int 		screen_h;
	int 		screen_w;
	int			tex_hei;
	int 		tex_wid;
	int 		tex_x;
	int 		tex_y;
	int			bpp;
	int 		tex_line;
	char 		*adr;
	double		side_x;
	double		side_y;
	double		l_x;
	double		l_y;
	double		del_x;
	double		del_y;
	double		rdir_x;
	double		rdir2_x;
	double		rdir_y;
	double		rdir2_y;
	double		z_pos;
	double		dist_row;
	double		f_step_x;
	double		f_step_y;
	double		floor_x;
	double		floor_y;
	int			celling_x;
	int			celling_y;
	double		cam;
	double		dist;
	double		wall_x;
	double		step;
	double 		tex_pos;
}				t_matrix;

typedef struct s_move
{
	int 		up;
	int			down;
	int			right;
	int			left;
	int			r_rot;
	int			l_rot;
	double 		r_m_rot;
	double 		l_m_rot;
	double 		mouse_cam;
	int			exit;
}				t_move;

typedef struct	s_player
{
	double		x;
	double		y;
	int			hp;
	int			ammo;
	int			dir;
	double		dir_x;
	double		dir_y;
	double		plan_x;
	double 		plan_y;
}				t_player;

typedef struct	s_f
{
	short int	r;
	short int	g;
	short int	b;
	short int 	flag;
	int 		rgb;
}				t_f;

typedef struct	s_struct
{
	short int	valid;
	int			width;
	int			height;
	int			scr_width;
	int			scr_height;
	int 		scr_swap_w;
	int 		scr_swap_h;
	char		**g_map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	t_f			f;
	t_f 		c;
	short int	save;
	t_player	resp_player;
}				t_map;

typedef struct	s_image
{
	void		*img;
	char		*adr;
	int			bpp;
	int 		line_len;
	int			iend;
}				t_image;

typedef struct	s_wht
{
	void 		*tex;
	char		*adr;
	int 		width;
	int 		height;
	int			bpp;
	int 		line_len;
	int			iend;
}				t_wht;

typedef struct	s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct	s_sprite
{
	t_pos		*pos;
	double		spr_x;
	double		spr_y;
	double		inde;
	double		trans_x;
	double		trans_y;
	int			spr_scr;
	int 		move_scr;
	int 		spr_hi;
	int 		spr_wi;
	int			draw_up_x;
	int			draw_up_y;
	int 		draw_down_x;
	int 		draw_down_y;
	int 		spr_len;
	int 		width;
	int 		height;
	int 		*spr;
	double		*spr_dist;
	void 		*tex;
	char		*adr;
	double		*wid_buf;
	int			bpp;
	int 		line_len;
	int			iend;
}				t_sprite;

typedef struct	s_tex
{
	t_wht		no;
	t_wht		so;
	t_wht		we;
	t_wht		ea;
	t_wht		skybox;
}				t_tex;

typedef struct	s_all
{
	double		xxx;
	double		yyy;
	void		*mlx;
	void		*win;
	int 		width_square;
	t_map		param;
	t_player	player;
	t_move		move;
	t_matrix	neo;
	t_image		img;
	t_tex		tex;
	t_sprite	sprite;
}				t_all;

t_all	ft_fornull(t_all xlm);
t_all	ft_fornull_2(t_all xlm);
t_map	ft_parser(t_map param, char *map);
t_map	ft_pars_reso(t_map param, char *map);
t_map	ft_pars_frgb(t_map param, char *map);
t_map	ft_pars_crgb(t_map param, char *map);
t_map	ft_pars_no(t_map param, char *map);
t_map	ft_pars_so(t_map param, char *map);
t_map	ft_pars_we(t_map param, char *map);
t_map	ft_pars_ea(t_map param, char *map);
t_map	ft_pars_s(t_map param, char *map);
int		ft_error(t_all xlm, int error);
int		drop_space(char **map);
char	*freesher(char *s1, char *s2, char *s3);
t_map	ft_valid(t_map param, int i, int j, int flaglen);
void	ft_draw_map(t_all *xlm, int x_print, int y_print);
void 	ft_draw_square(t_all *xlm, int x, int y, int color);
int 	key_hook(t_all *xlm);
int		key_press(int key, t_all *xlm);
int		key_release(int key, t_all *xlm);
//void	save_player(t_all *xlm);
void	ft_draw_beam(t_all *xlm);
t_map	dir_cos_sin(t_map param);
int		ft_render(t_all *xlm);
void 	ft_draw_line(int x, int draw_s, int draw_e, int color, t_all *xlm);
void	my_pixel_put(t_all *xlm, int x, int y, int color);
int		rgb_color(int r, int g, int b);
void	sprite_len(t_all *xlm);
void	sprite_sort(t_all *xlm);
//void 	chek_screen(t_all *xlm);
int 	mouse(int x, int y, t_all *xlm);
void	ft_texture(t_all *xlm);

#endif
