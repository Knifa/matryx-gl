cmake_minimum_required(VERSION 3.1)
project(matryxgl
  LANGUAGES CXX
)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

add_executable(matryxgl
  src/main.cxx
  src/matrix.cxx
  src/canvas.cxx
)

set_target_properties(matryxgl
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_link_libraries(matryxgl
  zmq
)

target_compile_options(matryxgl PRIVATE
  -Wall
)
