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
# define MAP_ERROR 5
# define NO_ERROR 6
# define SO_ERROR 7
# define WE_ERROR 8
# define EA_ERROR 9
# define S_ERROR 10
# define F_ERROR 11
# define C_ERROR 12
# include "../libft/libft.h"

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
	int			flag;
	int			type;
	int			temp;
}				t_map;

//void	cub3d(void);
t_map	ft_fornull(t_map param);
t_map	ft_parser(t_map param, char *map);
int		ft_error(int error);

#endif
