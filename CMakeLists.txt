cmake_minimum_required(VERSION 3.7)
project(Wolf3d)

include_directories(includes sdl/include/SDL2)

execute_process(COMMAND ${CMAKE_SOURCE_DIR}/sdl/bin/sdl2-config --libs OUTPUT_VARIABLE SDL2_CFLAGS_LIBS OUTPUT_STRIP_TRAILING_WHITESPACE)
message("SDL2_CFLAGS_LIBS=${SDL2_CFLAGS_LIBS};")


if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SDL2_CFLAGS_LIBS} -framework OpenGl")
endif()


set(HEADER_FILES includes/wolf3d.h)
set(SOURCE_FILES src/main.c src/error.c)

add_executable(Wolf3d ${SOURCE_FILES})

target_link_libraries(Wolf3d ${CMAKE_SOURCE_DIR}/libft/libft.a)