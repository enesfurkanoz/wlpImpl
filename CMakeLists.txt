# CMakeList.txt : CMake project for wlpImpl, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("wlpImpl")

set(WIN32 True)

# Add source to this project's executable.
#add_library("wlpImpl"   "wlpImpl.h" "wlpImpl.cpp")

add_executable("exec" "experiment.cpp" "wlpImpl.h" "wlpImpl.cpp")
#add_executable("exec"  "example.c")

# TODO: Add tests and install targets if needed.
