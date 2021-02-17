cmake_minimum_required(VERSION 3.17)
project(superCUB3D C)

set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
add_executable(superCUB3D ./cub3d.c ./parser_and_valid/ft_parser.c ./parser_and_valid/ft_pars_r_f_c.c
        ./parser_and_valid/ft_pars_no_so_we_ea_s.c ./parser_and_valid/ft_valid.c ./error_list/ft_error.c
        ./other/ft_other_fun.c ./other/ft_assignment.c ./draws/ft_draw.c ./pudge_hook/ft_hook.c ./texture/ft_texture.c
        ./sprite/ft_sprite.c ./other/ft_assignment_2.c ./pudge_hook/ft_key_and_mouse ./pudge_hook/ft_move.c ./draws/ft_draw_tex.c
        ./draws/ft_draw_cefl.c ./draws/ft_select_texture_for_draw.c ./draws/ft_draw_sprite.c ./rendering/ft_rendering.c
        ./draws/ft_draw_stvol.c ./draws/ft_draw_hud.c ./other/ft_screenshot.c ./pudge_hook/ft_action.c ./draws/ft_draw_map.c
        ./texture/ft_weapon_texture.c ./draws/ft_draw_tex_2.c ./sprite/ft_count_damage_sprite.c)
target_link_libraries(superCUB3D /Users/dpatrica/CLionProjects/superCUB3D/libft/libft.a
        /Users/dpatrica/CLionProjects/superCUB3D/minilibx_opengl/libmlx.a)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -framework OpenGL -framework Appkit")