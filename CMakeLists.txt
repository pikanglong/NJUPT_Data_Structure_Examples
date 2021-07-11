cmake_minimum_required(VERSION 3.19)
project(NJUPT_Data_Structure_Examples)

set(CMAKE_CXX_STANDARD 14)

file(GLOB APP_SOURCES src/*/*.cpp)

foreach( sourcefile ${APP_SOURCES} )
    get_filename_component( demo_name ${sourcefile} NAME_WE )
    add_executable( ${demo_name} ${sourcefile} )
endforeach( sourcefile ${APP_SOURCES} )