# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/05 21:31:17 by dpatrica          #+#    #+#              #
#    Updated: 2020/12/01 17:44:01 by dpatrica         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./cub3d.c\
			./parser_and_valid/ft_parser.c\
			./parser_and_valid/ft_pars_r_f_c.c\
			./parser_and_valid/ft_pars_no_so_we_ea_s.c\
			./parser_and_valid/ft_valid.c\
			./error_list/ft_error.c\
			./other/ft_other_fun.c\
			./other/ft_assignment.c\
			./draws/ft_draw.c\
			./pudge_hook/ft_hook.c\
			./texture/ft_texture.c\
			./other/ft_sprite.c\
			./other/ft_assignment_2.c\
			./pudge_hook/ft_key_and_mouse\
			./pudge_hook/ft_move.c\
			./draws/ft_draw_tex.c\
			./draws/ft_draw_cefl.c\
			./draws/ft_select_texture_for_draw.c

LIBSRCS	=	./libft/ft_strlen.c\
			./libft/ft_memset.c\
			./libft/ft_bzero.c\
			./libft/ft_memcpy.c\
			./libft/ft_memccpy.c\
			./libft/ft_memmove.c\
			./libft/ft_memchr.c\
			./libft/ft_memcmp.c\
			./libft/ft_strlcpy.c\
			./libft/ft_strlcat.c\
			./libft/ft_strchr.c\
			./libft/ft_strrchr.c\
			./libft/ft_strnstr.c\
			./libft/ft_strncmp.c\
			./libft/ft_isalpha.c\
			./libft/ft_isdigit.c\
			./libft/ft_isalnum.c\
			./libft/ft_isascii.c\
			./libft/ft_isprint.c\
			./libft/ft_toupper.c\
			./libft/ft_tolower.c\
			./libft/ft_atoi.c\
			./libft/ft_calloc.c\
			./libft/ft_strdup.c\
			./libft/ft_substr.c\
			./libft/ft_strjoin.c\
			./libft/ft_strtrim.c\
			./libft/ft_split.c\
			./libft/ft_putchar_fd.c\
			./libft/ft_putstr_fd.c\
			./libft/ft_putendl_fd.c\
			./libft/ft_putnbr_fd.c\
			./libft/ft_strmapi.c\
			./libft/ft_itoa.c\
			./libft/ft_digitlen.c\
			./libft/ft_mpldig.c\
			./libft/ft_putnbr.c\
			./libft/ft_ungitlen.c\
			./libft/ft_putstr.c\
			./libft/ft_dig16len.c\
			./libft/ft_digplen.c\
			./libft/get_next_line.c\
			./libft/ft_rhr.c\
			./libft/ft_mstr.c

HEAD	=	./includes/cub3d.h
NAME	= 	cub3D
LIBA	=	./libft/libft.a
LIBH	=	./libft/libft.h
MLX		=	./minilibx_opengl/libmlx.a libmlx.dylib
OBJS	=	$(SRCS:.c=.o)
LIBOBJS	=	$(LIBSRCS:.c=.o)

GCC		= 	gcc
FLAG	=	-Wall -Wextra# -Werror
FLAGMLX	=	-framework OpenGL -framework Appkit
RM		=	rm -f
C		=	-c
O		=	-o
AR		=	ar rc
MAKE_L	=	$(MAKE) -C ./libft
MAKE_FC	=	$(MAKE) fclean -C ./libft

all:		$(NAME)

.PHONY:		all clean fclean re

.c.o:
			$(GCC) $(FLAG) $(C) $< $(O) $(<:.c=.o)

$(NAME):	$(LIBA) $(OBJS)
			$(GCC) $(FLAG) $(FLAGMLX) $(O) $(NAME) $(MLX) $(LIBOBJS) $(OBJS)

$(LIBA):	$(LIBOBJS)
			$(MAKE_L)

$(OBJS):	$(HEAD)

$(LIBOBJS):	$(LIBH)

clean:
			$(RM) $(OBJS)
			$(MAKE_FC)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all