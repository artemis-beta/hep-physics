cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set( BOOST $ENV{BOOSTINCLUDE} )
set( CMAKE_GENERATOR ${CXX_LOC})

project(PHYSICSLIB)

file(GLOB EXAMPLES examples/*.cxx)

set( SRCFILES
    src/Units.cxx
    src/Constants.cxx
    src/LorentzVector.cxx
    src/Vector.cxx
    src/Particle.cxx
    src/DecayTable.cxx
    src/CommonParticles.cxx
    src/CommonNuclei.cxx
    src/NuclearPhysics.cxx
    src/Atom.cxx
    src/CommonMolecules.cxx
    src/Thermodynamics.cxx
    src/CommonCompounds.cxx
    src/Hydrocarbons.cxx
    src/ClassicalMechanics.cxx
    src/KplusDecTable.cxx
    src/PDF.cxx
    src/EquationSolver.cxx
    src/Epoch.cxx  
)

foreach(example ${EXAMPLES})
    get_filename_component(file_name ${example} NAME)
    string(REPLACE ".cxx" "" binary ${file_name})
    add_executable(${binary} ${example} ${SRCFILES})
    target_link_libraries(${binary} ${LIBS})
    target_include_directories(${binary} PRIVATE ${PROJECT_SOURCE_DIR}/include)
endforeach(example ${EXAMPLES})