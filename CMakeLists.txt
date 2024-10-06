cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(Simulation)

# Find Geant4 package, including UI and visualization drivers
find_package(Geant4 REQUIRED ui_all vis_all)

# Include Geant4 settings
include(${Geant4_USE_FILE})

# Find ROOT package
find_package(ROOT REQUIRED)

# Include directories
include_directories(${PROJECT_SOURCE_DIR})

# Collect source and header files
file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)

# Add executable
add_executable(main main.cc ${sources} ${headers})

# Link against Geant4 and ROOT libraries
target_link_libraries(main ${Geant4_LIBRARIES} ${ROOT_LIBRARIES})

# Add custom target
add_custom_target(Simulation DEPENDS main)