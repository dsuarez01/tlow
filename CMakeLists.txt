cmake_minimum_required(VERSION 3.20)
project(tlow VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  onnx
  GIT_REPOSITORY https://github.com/onnx/onnx.git
  GIT_TAG        v1.17.0
)

set(BUILD_ONNX_PYTHON OFF CACHE BOOL "" FORCE)
set(ONNX_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(ONNX_BUILD_BENCHMARKS OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(onnx)

set(LLVM_ENABLE_PROJECTS "mlir" CACHE STRING "")
set(LLVM_TARGETS_TO_BUILD "X86;AArch64;NVPTX;AMDGPU" CACHE STRING "")
set(LLVM_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(LLVM_INCLUDE_TESTS OFF CACHE BOOL "" FORCE)

add_subdirectory(third_party/llvm-project/llvm)

find_package(MLIR REQUIRED CONFIG HINTS ${CMAKE_BINARY_DIR}/lib/cmake/mlir)

add_subdirectory(lib/Runtime)
add_subdirectory(lib/Importer)
add_subdirectory(lib/Transforms)
add_subdirectory(lib/Codegen)

add_subdirectory(tools/tlow)