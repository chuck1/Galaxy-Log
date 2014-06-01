CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

add_executable(test main.cpp)



SET(BOOST_ROOT /scratch/usr)
SET(BOOST_LIBRARY_DIR /scratch/usr/lib)
SET(Boost_NO_SYSTEM_PATHS ON)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
FIND_PACKAGE(
	Boost 1.55
	COMPONENTS log system thread
	REQUIRED)



MESSAGE(STATUS "boost: ${Boost_LIBRARIES}")

SET(libs ${libs}
	Galaxy-Log
	${Boost_LIBRARIES}
	pthread
	rt
	)

#SET(libs ${libs} ${Boost_PROGRAM_OPTIONS_LIBRARY})


SET(libs ${libs} ${libs})

target_link_libraries(test ${libs})



