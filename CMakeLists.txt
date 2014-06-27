cmake_minimum_required (VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

project(galaxy_log)

SET(galaxy_log_STATIC TRUE)
SET(galaxy_log_SHARED TRUE)

find_package(CMakeHelper)


set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_STATIC_RUNTIME OFF)
add_definitions( -DBOOST_ALL_DYN_LINK )

FIND_PACKAGE(Boost 1.55 COMPONENTS log system thread REQUIRED)


# include_directories

# submodule

# custom include extensions
#set(INCLUDE_EXTENSIONS obj)

#SET(GRU_VERSION 0.1.1)

SET(libs
	${Boost_LIBRARIES}
	pthread
	rt)

cmh_library()

add_subdirectory(test)


