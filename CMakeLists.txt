cmake_minimum_required(VERSION 3.17)
project(superCUB3D C)

set(CMAKE_C_STANDARD 99)

add_executable(superCUB3D ./cub3d.c ./parser_and_valid/ft_parser.c ./parser_and_valid/ft_pars_r_f_c.c
        ./parser_and_valid/ft_pars_no_so_we_ea_s.c ./parser_and_valid/ft_valid.c ./error_list/ft_error.c
        ./other/ft_other_fun.c ./other/ft_assignment.c ./draws/ft_draw.c ./pudge_hook/ft_hook.c ./texture/ft_texture.c
        ./other/ft_sprite.c)
target_link_libraries(superCUB3D /Users/dpatrica/CLionProjects/superCUB3D/libft/libft.a
        /Users/dpatrica/CLionProjects/superCUB3D/minilibx_opengl/libmlx.a)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -framework OpenGL -framework Appkit")