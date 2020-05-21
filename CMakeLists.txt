cmake_minimum_required( VERSION 3.10 )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib )
find_package( Boost REQUIRED )

project( PhysicsLib )

file( GLOB_RECURSE SRCS src/*.cxx )

add_library( ${PROJECT_NAME} SHARED ${SRCS} )

target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} ${LIBS} )
target_include_directories( ${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include
       			    ${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIRS} )

add_subdirectory( examples )
add_subdirectory( tests )
