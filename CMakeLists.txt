cmake_minimum_required (VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

project(galaxy_log)

find_package(CMakeHelper)

cmh_boost_shared()
FIND_PACKAGE(Boost 1.55 COMPONENTS
	system
	thread
	REQUIRED)

SET(libs
	${Boost_LIBRARIES}
	pthread
	rt)

cmh_static_library()

project(galaxy_log_shared)

find_package(CMakeHelper)

cmh_boost_shared()
FIND_PACKAGE(Boost 1.55 COMPONENTS
	system
	thread
	REQUIRED)

SET(libs
	${Boost_LIBRARIES}
	pthread
	rt)

cmh_shared_library()

add_subdirectory(test)


