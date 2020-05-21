project( PhysicsLib_Examples )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )

file( GLOB_RECURSE EXAMPLES ${CMAKE_SOURCE_DIR}/examples/*.cxx )

foreach( EXAMPLE ${EXAMPLES} )
	get_filename_component( EXAMPLE_NAME ${EXAMPLE} NAME_WLE )
	add_executable( ${EXAMPLE_NAME} ${EXAMPLE} )
	target_include_directories( ${EXAMPLE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include )
	target_link_libraries( ${EXAMPLE_NAME} PUBLIC PhysicsLib )
endforeach()
