cmake_minimum_required(VERSION 3.5)
project(MyProject)

# Find Geant4 package, activating all available UI and Vis drivers by default
find_package(Geant4 REQUIRED ui_all vis_all)

# Find ROOT package
find_package(ROOT REQUIRED)

# Setup include directories for Geant4 and ROOT
include(${Geant4_USE_FILE})
include_directories(${ROOT_INCLUDE_DIRS})

# Add executable
add_executable(main main.cc MyRunAction.cc MySensitiveDetector.cc MyHit.cc MyDetectorConstruction.cc MyPrimaryGeneratorAction.cc)

# Link against Geant4 and ROOT libraries
target_link_libraries(main ${Geant4_LIBRARIES} ${ROOT_LIBRARIES})








