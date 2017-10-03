cmake_minimum_required(VERSION 3.7)
set(CMAKE_C_STANDARD 99)
project(Wolf3d)

include_directories(includes)

set(SOURCE_FILES src/main.c src/error.c src/sdl_put_pixel.c src/sdl_event_hook.c
    src/exit.c src/sdl_close.c src/main_loop.c src/sdl_create_rgba_image.c
    src/sdl_update_window.c src/draw_img.c src/sdl_create_window.c
        src/read_map.c src/read_file.c src/arr_2d.c includes/arr_2d.h src/fps.c
    src/sdl_put_text.c src/calc_all.c includes/wolf3d.h includes/define.h includes/libft.h)
add_executable(Wolf3d ${SOURCE_FILES})

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    message("Mac OS X!!!")
    #SDL_HEADER
    set(SDL2_HEADRS /nfs/2016/a/akrotov/Library/Frameworks/SDL2.framework)
    set(SDL2_TTF_HEADRS /nfs/2016/a/akrotov/Library/Frameworks/SDL2_ttf.framework)
    set(SDL_IMAGE_HEADRS //nfs/2016/a/akrotov/Library/Frameworks/SDL2_image.framework)
    #FLAGS
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
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
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lSDL2 -lSDL2_ttf -lm")
endif()

target_link_libraries(Wolf3d ${CMAKE_SOURCE_DIR}/libft/libft.a)
