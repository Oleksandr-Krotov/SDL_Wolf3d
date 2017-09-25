# sdl2 cmake project-config input for ./configure scripts

set(prefix "/nfs/2016/a/akrotov/akrotov/Wolf3d/sdl") 
set(exec_prefix "${prefix}")
set(libdir "${exec_prefix}/lib")
set(SDL2_PREFIX "/nfs/2016/a/akrotov/akrotov/Wolf3d/sdl")
set(SDL2_EXEC_PREFIX "/nfs/2016/a/akrotov/akrotov/Wolf3d/sdl")
set(SDL2_LIBDIR "${exec_prefix}/lib")
set(SDL2_INCLUDE_DIRS "${prefix}/include/SDL2")
set(SDL2_LIBRARIES "-L${SDL2_LIBDIR}  -lSDL2 ")
string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
