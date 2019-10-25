cmake_minimum_required(VERSION 3.1)
project(matryx-gl
  LANGUAGES CXX
)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

add_executable(matryx-gl
  src/main.cxx
  src/matrix.cxx
  src/canvas.cxx
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
