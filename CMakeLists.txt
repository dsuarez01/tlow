cmake_minimum_required(VERSION 3.20)
project(tlow VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(LLVM_ENABLE_PROJECTS "mlir" CACHE STRING "")
set(LLVM_TARGETS_TO_BUILD "X86;AArch64;NVPTX;AMDGPU" CACHE STRING "")
set(LLVM_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(LLVM_INCLUDE_TESTS OFF CACHE BOOL "" FORCE)

set(MLIR_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(MLIR_INCLUDE_TESTS OFF CACHE BOOL "" FORCE)

# MLIR
add_subdirectory(third_party/llvm-project/llvm)
find_package(MLIR REQUIRED CONFIG HINTS ${CMAKE_BINARY_DIR}/lib/cmake/mlir)

# ONNX Runtime
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(OnnxRuntime REQUIRED)

add_subdirectory(lib/Frontend)
add_subdirectory(lib/Transforms)
add_subdirectory(lib/Codegen)

add_subdirectory(tools/tlow)
add_subdirectory(tools/tlow-opt)