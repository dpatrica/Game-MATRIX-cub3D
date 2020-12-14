//
// Created by Daisey Patrica on 12/6/20.
//

#ifndef CUB3D_H
# define CUB3D_H

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
//# define NO_ERROR
//# define SO_ERROR
//# define WE_ERROR
//# define EA_ERROR
//# define S_ERROR
//# define F_ERROR
//# define C_ERROR
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_f
{
	short int	r;
	short int	g;
	short int	b;
	short int 	flag;
}				t_f;

typedef struct	s_struct
{
	short int	valid;
	int			width;
	int			height;
	char		**g_map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	t_f			f;
	t_f 		c;
	short int	save;
	int			type;
	int			temp;
}				t_map;

//void	cub3d(void);
t_map	ft_fornull(t_map param);
t_map	ft_parser(t_map param, char *map);
t_map	ft_pars_reso(t_map param, char *map);
t_map	ft_pars_frgb(t_map param, char *map);
t_map	ft_pars_crgb(t_map param, char *map);
t_map	ft_pars_no(t_map param, char *map);
t_map	ft_pars_so(t_map param, char *map);
t_map	ft_pars_we(t_map param, char *map);
t_map	ft_pars_ea(t_map param, char *map);
t_map	ft_pars_s(t_map param, char *map);
int		ft_error(t_map param, int error);
int		drop_space(char **map);
char	*freesher(char *s1, char *s2, char *s3);
t_map	ft_valid(t_map param, int flaglen, int i, int j);
#endif
