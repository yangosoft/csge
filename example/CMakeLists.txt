cmake_minimum_required(VERSION 3.8)

project(CSGEExample VERSION ${CSGE_VERSION_MAJOR}.${CSGE_VERSION_MINOR} LANGUAGES CXX) 


include (GNUInstallDirs)

set(SDL2_IMAGE_INCLUDE_DIRS "/usr/include/SDL2")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
# find_package(SDL2_image REQUIRED)

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

include_directories(../core/inc/)
include_directories(inc)

set (SDL2_IMAGE_LIBRARIES "-lSDL2_image")


set(HEADER_FILES inc/app.h
inc/config.h
inc/engine.h
inc/resources.h
inc/shaders.h)

set (SOURCE_FILES src/app.cpp
src/config.cpp
src/engine.cpp
src/main.cpp
src/resources.cpp
src/shaders.cpp)



add_executable(CSGEExample ${SOURCE_FILES})
target_link_libraries(CSGEExample ${SDL2_LIBRARIES}${SDL2_IMAGE_LIBRARIES} ${CSGECore_LIBRARIES} ${OPENGL_LIBRARIES})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/dist/tex    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set_target_properties(CSGEExample PROPERTIES VERSION ${CSGE_VERSION_MAJOR})
set_target_properties(CSGEExample PROPERTIES SOVERSION ${CSGE_VERSION_MAJOR})





         
if( ENABLE_TEST )
    message("Unit test enabled")
#     include(${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt)
endif()
