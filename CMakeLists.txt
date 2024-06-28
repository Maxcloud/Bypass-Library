cmake_minimum_required(VERSION 3.28)

# project name
project(bypass-library)

# set the c++ standard
set(CMAKE_CXX_STANDARD 17)

# provide the source files
file(GLOB_RECURSE SOURCES "log/*.cpp" "log/*.h")
file(GLOB_RECURSE SOURCES "nmco/*.cpp" "nmco/*.h")
file(GLOB_RECURSE SOURCES "generic.cpp" "generic.hpp")
file(GLOB_RECURSE SOURCES "memory.cpp" "memory.hpp")

# define the static library
add_library(bypass-library STATIC ${SOURCES})

# specify include directories for the library
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# specify any additional libraries to link
find_path(DETOURS_INCLUDE_DIRS "detours/detours.h")
find_library(DETOURS_LIBRARY detours REQUIRED)

# detours
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${DETOURS_INCLUDE_DIRS})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${DETOURS_LIBRARY})

# include GNUInstallDirs module
include(GNUInstallDirs)

# library installation
install(TARGETS ${CMAKE_PROJECT_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# header installation
install(DIRECTORY log/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/log FILES_MATCHING PATTERN "*.h")
install(DIRECTORY nmco/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/nmco FILES_MATCHING PATTERN "*.h")
install(FILES generic.hpp memory.hpp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# run command to install lib and header files
# cmake --build . --target install