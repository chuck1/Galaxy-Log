cmake_minimum_required (VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

project(Galaxy-Log)

find_package(CMakeHelper)

# include_directories

# submodule

# custom include extensions
#set(INCLUDE_EXTENSIONS obj)

#SET(GRU_VERSION 0.1.1)

cmh_header_only()

add_subdirectory(test)


