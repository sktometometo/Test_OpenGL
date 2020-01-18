cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(Test_OpenGL)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# include
include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR})


# executables
add_executable(sample2d_01 src/sample2d_01.cpp)
target_link_libraries(sample2d_01 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

add_executable(sample2d_02 src/sample2d_02.cpp)
target_link_libraries(sample2d_02 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

add_executable(sample2d_03 src/sample2d_03.cpp)
target_link_libraries(sample2d_03 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

# 3d examples
add_executable(sample3d_01 src/sample3d_01.cpp)
target_link_libraries(sample3d_01 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

add_executable(sample3d_02 src/sample3d_02.cpp)
target_link_libraries(sample3d_02 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
