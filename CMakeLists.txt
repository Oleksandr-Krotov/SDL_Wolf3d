cmake_minimum_required(VERSION 3.7)
set(CMAKE_C_STANDARD 99)
project(Wolf3d)

include_directories(includes)

set(SOURCE_FILES
        src/action.c
        src/arr_2d.c
        src/change_light_texture.c
        src/combo_sort.c
        src/dda.c
        src/design_garden.c
        src/design_start_scene.c
        src/destruct_garden_scene.c
        src/destruct_start_scene.c
        src/draw_bar.c
        src/draw_line_wall.c
        src/draw_sprite_stripe.c
        src/error.c
        src/event_hook_garden.c
        src/first_init_garden.c
        src/fps.c
        src/free_main.c
        src/free_map.c
        src/ft_ray_cast.c
        src/ft_ray_cast_sprite.c
        src/ft_sdl_close.c
        src/ft_sdl_create_wnd_renderer.c
        src/ft_sdl_event_hook.c
        src/ft_sdl_init.c
        src/ft_sdl_init_sound.c
        src/ft_sdl_set_rect.c
        src/ft_sdl_texture.c
        src/ft_sdl_ttf.c
        src/ft_sdl_update_window_size.c
        src/garden.c
        src/get_drop.c
        src/get_map_size.c
        src/init_all_scene.c
        src/init_garden.c
        src/init_sdl_insomnia.c
        src/init_start_scene.c
        src/load_assets_garden.c
        src/main.c
        src/main_init.c
        src/main_loop.c
        src/msg_lock.c
        src/read_file.c
        src/read_map.c
        src/scream_event_garden.c
        src/set_ds_param.c
        src/set_rc_param.c
        src/sort_sprite.c
        src/start.c
        src/torch.c
        src/z_buff.c
        includes/arr_2d.h
        includes/define.h
        includes/error.h
        includes/fps.h
        includes/garden.h
        includes/libft.h
        includes/mysdl.h
        includes/ray_cast.h
        includes/start.h
        includes/type.h
        includes/wolf3d.h)

add_executable(Wolf3d ${SOURCE_FILES})

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    message("Mac OS X!!!")
    #SDL_HEADER
    set(SDL2_HEADRS /Users/akrotov/Library/Frameworks/SDL2.framework/Headers)
    set(SDL2_TTF_HEADRS /Users/akrotov/Library/Frameworks/SDL2_ttf.framework/Headers)
    set(SDL_IMAGE_HEADRS /Users/akrotov/Library/Frameworks/SDL2_image.framework/Headers)
    #FLAGS
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -F ./SDL -O3 -framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer")
    #INCLUDES
    include_directories(${SDL2_HEADRS}, ${SDL2_TTF_HEADRS} ${SDL2_IMAGE_HEADRS})
    #SDL_LIBRARY
    find_library(SDL2_LIBRARY SDL2)
    find_library(SDL2_TTF_LIBRARY SDL2_ttf)
    find_library(SDL2_IMAGE_LIBRARY SDL2_image)
    target_link_libraries(Wolf3d ${SDL2_LIBRARY})
    target_link_libraries(Wolf3d ${SDL2_TTF_LIBRARY})
    target_link_libraries(Wolf3d ${SDL2_IMAGE_LIBRARY})
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message("Linux!!!")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lm")
endif()

target_link_libraries(Wolf3d ${CMAKE_SOURCE_DIR}/libft/libft.a)
