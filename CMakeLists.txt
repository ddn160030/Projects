cmake_minimum_required(VERSION 3.10)
project(cmake_tutorials)

# Set C++ standard early
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Debug messages
message(STATUS "CMAKE_VERSION=${CMAKE_VERSION}")
message(STATUS "CMAKE_MAJOR_VERSION=${CMAKE_MAJOR_VERSION}")
message(STATUS "CMAKE_MINOR_VERSION=${CMAKE_MINOR_VERSION}")
message(STATUS "CMAKE_PATCH_VERSION=${CMAKE_PATCH_VERSION}")
message(STATUS "Cache Name = $CACHE{Name}")

# Find OpenCV
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV_VERSION: ${OpenCV_VERSION}")
message(STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Create the library from file1
add_library(library1
        src/file1.cpp
)

# Set include directories for library1
target_include_directories(library1 PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        ${OpenCV_INCLUDE_DIRS}
)

# Create the main executable
add_executable(${PROJECT_NAME}
        src/main.cpp
        src/printer.cpp
)

# Link libraries to the executable
target_link_libraries(${PROJECT_NAME}
        PUBLIC library1
        PRIVATE ${OpenCV_LIBS}
)



# Add test directory
add_subdirectory(test)