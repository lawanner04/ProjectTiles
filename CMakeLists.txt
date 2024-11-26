# Specify the minimum CMake version and project name
cmake_minimum_required(VERSION 3.10)
project(main)

# Set C++ standard and compile options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Define directories
set(SRC_DIR src)
set(INC_DIR include)

# Include directories
include_directories(${INC_DIR})
include_directories(/opt/homebrew/include)  # SFML include directory
include_directories(${CMAKE_SOURCE_DIR}/tmxlite/include)  # Path to tmxlite headers

# Set output directory for build artifacts


# Gather all source files
file(GLOB SOURCES
    "*.cpp"              # Root directory .cpp files
    "${SRC_DIR}/*.cpp"   # Source directory .cpp files
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Link SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

# Link tmxlite (dynamic library)
link_directories(${CMAKE_SOURCE_DIR}/tmxlite/build)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/tmxlite/build/libtmxlite.dylib)

# Add rpath to tmxlite library directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    BUILD_RPATH "${CMAKE_SOURCE_DIR}/tmxlite/build"
)
