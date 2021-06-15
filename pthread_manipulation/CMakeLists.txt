# Defines the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Project Name
set(EXEC_NAME TestThread)
set(PROJ_NAME pthread_manipulation)

# Define Project
project(${PROJ_NAME})

# Set CMAKE_INSTALL_PREFIX to define install directory
set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install" CACHE PATH "Default Install Path" FORCE)

# Set "Release" as default build type
set(CMAKE_BUILD_TYPE "Release")

# Define the folder of Install Includes, libraries and Runtime Files. (.h, .hpp, .ilk, .exe, .dll, .lib, .exp etc.)
set(PROJECT_INCLUDES        ${CMAKE_INSTALL_PREFIX}/include)
set(PROJECT_LIBS            ${CMAKE_INSTALL_PREFIX}/lib)
set(PROJECT_BINARIES        ${CMAKE_INSTALL_PREFIX}/bin)

# Define the folder of includes and source files
set(PROJECT_SOURCES         ${CMAKE_SOURCE_DIR}/src)
set(PROJECT_INCLUDES        ${CMAKE_SOURCE_DIR}/include)

include_directories(${PROJECT_INCLUDES})

# Collect sources into the variable
file(GLOB_RECURSE SOURCES
        "src/*.c"
        "src/*.cpp"
        "src/*.cxx"
)

add_executable(${EXEC_NAME} ${SOURCES})
set_target_properties(${EXEC_NAME} PROPERTIES LINKER_LANGUAGE C)

# Linking libraries to Exec
target_link_libraries(${EXEC_NAME} pthread)

# Command to output information to the console
# Useful for displaying errors, warnings, and debugging
target_compile_options(${EXEC_NAME} PRIVATE -Wno-long-long -Wno-varargs)

# Define installation folders
install(TARGETS ${EXEC_NAME} 
        RUNTIME DESTINATION ${PROJECT_BINARIES}
        LIBRARY DESTINATION ${PROJECT_BINARIES}
        ARCHIVE DESTINATION ${PROJECT_LIBS})