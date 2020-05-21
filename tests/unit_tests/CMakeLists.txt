file( GLOB_RECURSE TESTS "*.cxx" )

set( UNITTESTS ${PROJECT_NAME}_unit-tests )

add_executable( ${UNITTESTS} ${TESTS} )

target_include_directories( ${UNITTESTS} PRIVATE ${GTEST_INCLUDE_DIRS} )
target_include_directories( ${UNITTESTS} PUBLIC ${Boost_INCLUDE_DIRS} )
target_include_directories( ${UNITTESTS} PUBLIC ${CMAKE_SOURCE_DIR}/include )

target_include_directories( ${UNITTESTS} PRIVATE ${GMOCK_INCLUDE_DIRS} )
target_link_libraries( ${UNITTESTS} PUBLIC ${Boost_LIBRARIES} )
target_link_libraries( ${UNITTESTS} PRIVATE PhysicsLib )
target_link_libraries( ${UNITTESTS} PRIVATE ${PROJECT_LIBS} ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} )

include( GoogleTest )
gtest_discover_tests( ${UNITTESTS} )
