cmake_minimum_required(VERSION 3.7)
set(CMAKE_C_STANDARD 99)
project(Wolf3d)

include_directories(includes)

execute_process(COMMAND ${CMAKE_SOURCE_DIR}/sdl/bin/sdl2-config --libs OUTPUT_VARIABLE SDL2_CFLAGS_LIBS OUTPUT_STRIP_TRAILING_WHITESPACE)
message("SDL2_CFLAGS_LIBS=${SDL2_CFLAGS_LIBS};")


if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    message("UNIX!!!")
    include_directories(includes sdl/include)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SDL2_CFLAGS_LIBS} -framework OpenGl")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message("Linux!!!")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lSDL2 -lSDL2_ttf -lm")
endif()


set(HEADER_FILES includes/wolf3d.h)
set(SOURCE_FILES src/main.c src/error.c src/sdl_put_pixel.c src/sdl_event_hook.c src/exit.c src/sdl_close.c src/main_loop.c src/sdl_create_rgba_image.c src/sdl_update_window.c includes/define.h includes/wolf3d.h src/draw_img.c src/sdl_create_window.c test.c src/read_map.c src/read_file.c src/arr_2d.c includes/arr_2d.h src/fps.c src/sdl_put_text.c)

add_executable(Wolf3d ${SOURCE_FILES})

target_link_libraries(Wolf3d ${CMAKE_SOURCE_DIR}/libft/libft.a)