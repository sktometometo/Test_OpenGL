cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(Test_OpenGL)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options)

message("EIGEN3_INCLUDE_DIRS: ${EIGEN3_INCLUDE_DIRS}")

# include
include_directories(
    ${OPENGL_INCLUDE_DIR}
    ${GLUT_INCLUDE_DIR}
    ${EIGEN3_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
    libs/stl_reader # for stl_reader headers
)


# executables
add_executable(sample2d_01
    src/sample2d_01.cpp
)
target_link_libraries(sample2d_01
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
)

add_executable(sample2d_02
    src/sample2d_02.cpp
)
target_link_libraries(sample2d_02
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
)

add_executable(sample2d_03
    src/sample2d_03.cpp
)
target_link_libraries(sample2d_03
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
)


# 3d examples
add_executable(sample3d_01
    src/sample3d_01.cpp
)
target_link_libraries(sample3d_01
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
)

add_executable(sample3d_02
    src/sample3d_02.cpp
)
target_link_libraries(sample3d_02
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
)

add_executable(sample3d_with_stl
    src/sample3d_with_stl.cpp
)
target_link_libraries(sample3d_with_stl
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    ${Boost_LIBRARIES}
)
