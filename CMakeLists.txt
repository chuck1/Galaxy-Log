cmake_minimum_required (VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

project(Galaxy-Log)

find_package(CMakeHelper)

FIND_PACKAGE(Boost 1.55 COMPONENTS log system thread)


# include_directories

# submodule

# custom include extensions
#set(INCLUDE_EXTENSIONS obj)

#SET(GRU_VERSION 0.1.1)

SET(libs ${libs} Galaxy-Log ${Boost_LIBRARIES} pthread rt)

cmh_static_library()

add_subdirectory(test)


