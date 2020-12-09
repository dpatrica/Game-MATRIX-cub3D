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
}				t_f;

typedef struct	s_struct
{
	short int	valid;
	short int	width;
	short int	height;
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
int		ft_error(int error);

#endif
