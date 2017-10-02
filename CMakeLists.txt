cmake_minimum_required(VERSION 3.7)
set(CMAKE_C_STANDARD 99)
project(Wolf3d)

include_directories(includes)

set(HEADER_FILES includes/wolf3d.h)
set(SOURCE_FILES src/main.c src/error.c src/sdl_put_pixel.c src/sdl_event_hook.c src/exit.c src/sdl_close.c src/main_loop.c src/sdl_create_rgba_image.c src/sdl_update_window.c includes/define.h includes/wolf3d.h src/draw_img.c src/sdl_create_window.c test.c src/read_map.c src/read_file.c src/arr_2d.c includes/arr_2d.h src/fps.c src/sdl_put_text.c src/calc_all.c)
add_executable(Wolf3d ${SOURCE_FILES})

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    message("Mac OS X!!!")
    #SDL_HEADER
    set(SDL2_LIBRARY /nfs/2016/a/akrotov/Library/Frameworks/SDL2.framework)
    set(SDL2_TTF_LIBRARY /nfs/2016/a/akrotov/Library/Frameworks/SDL2_ttf.framework)
    #FLAGS
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
    #INCLUDES
    include_directories(${SDL2_LIBRARY}, ${SDL2_TTF_LIBRARY})
    #SDL_LIBRARY
    find_library(SDL2_LIBRARY SDL2)
    find_library(SDL2_TTF_LIBRARY SDL2_ttf)
    target_link_libraries(Wolf3d ${SDL2_LIBRARY})
    target_link_libraries(Wolf3d ${SDL2_TTF_LIBRARY})
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message("Linux!!!")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lSDL2 -lSDL2_ttf -lm")
endif()

target_link_libraries(Wolf3d ${CMAKE_SOURCE_DIR}/libft/libft.a)
