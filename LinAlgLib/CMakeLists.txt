# CMakeList.txt : CMake project for LinAlgLib, include source and define
# project specific logic here.
#

# Declare the library
add_library(LinAlgLib "Matrix.hpp")
set_target_properties(LinAlgLib PROPERTIES LINKER_LANGUAGE CXX)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LinAlgLib PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
add_subdirectory ("Tests")