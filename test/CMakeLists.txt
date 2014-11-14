CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

FIND_PACKAGE(CMakeHelper)

PROJECT(test_galaxy_log)
INCLUDE(../../../../../config.cmake)
INCLUDE(cmh_build_config)

#ADD_DEFINITIONS("-DGLM_FORCE_RADIANS")

MESSAGE(STATUS "${libs}")

include(cmh_executable)

