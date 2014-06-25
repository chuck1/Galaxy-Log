CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

PROJECT(test)

INCLUDE($ENV{HOME}/.config.cmake)

SET(libs galaxy_log ${libs})

link_exe()

