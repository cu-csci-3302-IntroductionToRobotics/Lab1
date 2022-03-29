cmake_minimum_required(VERSION 3.0)

# Setup the project.
# Its name is defined to be the controller directory name.
get_filename_component(PROJECT ${CMAKE_SOURCE_DIR} NAME)
project(${PROJECT})

file(GLOB SOURCES app/*.cpp code/*.cpp)

message("env is : $ENV{WEBOTS_HOME}")

set( WEBOTS_HOME $ENV{WEBOTS_HOME})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/modules)
set(IS_ENV_WEBOTS_HOME $ENV{WEBOTS_HOME})
find_package(Webots REQUIRED)

include_directories(${WEBOTS_INCLUDE_CPP_DIR})
message("libs-> ${WEBOTS_LIBRARIES}")
message("libs-> ${WEBOTS_LIBRARY_CPP}")
message("libs-> ${WEBOTS_LIBRARY_C}")
add_executable(run_lab ${SOURCES})
target_link_libraries(run_lab ${WEBOTS_LIBRARIES} )


# Link with the Webots controller library.
# link_directories($ENV{WEBOTS_HOME}/lib/controller)
# set (LIBRARIES ${CMAKE_SHARED_LIBRARY_PREFIX}CppController${CMAKE_SHARED_LIBRARY_SUFFIX})
# include_directories($ENV{WEBOTS_HOME}/include/controller/cpp)

# Setup the target executable.
# add_executable(${PROJECT} main.cpp)
# target_link_libraries(${PROJECT} ${LIBRARIES})
# add_executable(super  main_supervisor.cpp)
# target_link_libraries(super ${LIBRARIES})

# Copy the target executable at the right location.
# add_custom_command(TARGET ${PROJECT} POST_BUILD COMMAND ${CMAKE_COMMAND} -E
#   copy ${CMAKE_BINARY_DIR}/${PROJECT} ${CMAKE_SOURCE_DIR}
# )
