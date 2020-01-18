cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(Test_OpenGL)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# include
include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR})


# executables
add_executable(sample_01 src/sample_01.cpp)
target_link_libraries(sample_01 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

add_executable(sample_02 src/sample_02.cpp)
target_link_libraries(sample_02 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

add_executable(sample_03 src/sample_03.cpp)
target_link_libraries(sample_03 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

add_executable(sample_04 src/sample_04.cpp)
target_link_libraries(sample_04 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

add_executable(sample_05 src/sample_05.cpp)
target_link_libraries(sample_05 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

add_executable(sample_06 src/sample_06.cpp)
target_link_libraries(sample_06 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

add_executable(sample_07 src/sample_07.cpp)
target_link_libraries(sample_07 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

add_executable(sample_08 src/sample_08.cpp)
target_link_libraries(sample_08 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

# 3d examples
add_executable(sample3d_01 src/sample3d_01.cpp)
target_link_libraries(sample3d_01 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

add_executable(sample3d_02 src/sample3d_02.cpp)
target_link_libraries(sample3d_02 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
