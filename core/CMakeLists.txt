cmake_minimum_required(VERSION 3.8)

project(CSGECore VERSION ${CSGE_VERSION_MAJOR}.${CSGE_VERSION_MINOR} LANGUAGES CXX) 


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


include_directories(inc)

set (SDL2_IMAGE_LIBRARIES "-lSDL2_image")


set(HEADER_FILES "inc/core/program.h"
"inc/core/quadbatch.h"
"inc/core/quad.h"
"inc/core/scene.h"
"inc/core/shader.h"
"inc/core/sprite.h"
"inc/core/texture.h"
"inc/core/window.h"
"inc/core/node.h"
"inc/core/nodelist.h")

set (SOURCE_FILES src/program.cpp
src/quadbatch.cpp
src/quad.cpp
src/scene.cpp
src/shader.cpp
src/sprite.cpp
src/texture.cpp
src/window.cpp
src/node.cpp)



add_library(CSGECore SHARED ${SOURCE_FILES})
target_link_libraries(CSGECore ${SDL2_LIBRARIES}${SDL2_IMAGE_LIBRARIES})



set_target_properties(CSGECore PROPERTIES VERSION ${CSGE_VERSION_MAJOR})
set_target_properties(CSGECore PROPERTIES SOVERSION ${CSGE_VERSION_MAJOR})

set( sockets_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/inc" CACHE STRING "Include-directories for sockets" FORCE )


add_library(CSGE::CSGECore ALIAS CSGECore)





install (TARGETS CSGECore EXPORT CSGECoreTargets 
         LIBRARY DESTINATION lib/csge
         INCLUDES DESTINATION include/csge
         PUBLIC_HEADER DESTINATION include/csge)
        
message ("CSGECoreTargets ${CSGECoreTargets}")
install (EXPORT CSGECoreTargets 
         FILE   CSGECoreTargets.cmake
         NAMESPACE CppUtils::
         DESTINATION lib/cmake/csge/CSGECore
         )
         
install (DIRECTORY inc/core 
         DESTINATION include/csge)

include (CMakePackageConfigHelpers)
write_basic_package_version_file("CSGECoreConfigVersion.cmake" VERSION  ${CSGE_VERSION_MAJOR} COMPATIBILITY SameMajorVersion)
install (FILES "CSGECoreConfig.cmake" ${CMAKE_CURRENT_BINARY_DIR}/CSGECoreConfigVersion.cmake
         DESTINATION lib/cmake/csge/CSGECore)


         
set (CSGECore_LIBRARIES CSGECore CACHE STRING "CSGE libs" FORCE)
         
if( ENABLE_TEST )
    message("Unit test enabled")
#     include(${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt)
endif()
