cmake_minimum_required(VERSION 3.1)
project(matryx-gl
  LANGUAGES CXX
)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(matryx-gl
  src/Canvas.cpp
  src/FrameTimer.cpp
  src/main.cpp
  src/Matrix.cpp
  src/Scene.cpp
  src/scenes/WatermelonPlasmaScene.cpp
)

set_target_properties(matryx-gl
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_link_libraries(matryx-gl
  zmq
)

target_compile_options(matryx-gl PRIVATE
  -Wall
)

target_compile_features(matryx-gl PUBLIC cxx_std_11)
set_target_properties(matryx-gl PROPERTIES CXX_EXTENSIONS OFF)
