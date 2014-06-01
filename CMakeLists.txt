cmake_minimum_required (VERSION 2.8.8)

SET(CMAKE_CXX_COMPILER /scratch/usr/bin/g++)
SET(CMAKE_INSTALL_PREFIX $ENV{HOME}/usr)

project(Galaxy-Log)

find_package(CMakeHelper)

# include_directories

# submodule

# custom include extensions
#set(INCLUDE_EXTENSIONS obj)

#SET(GRU_VERSION 0.1.1)

cmh_static_library()

add_subdirectory(test)


