cmake_minimum_required(VERSION 3.20)
project(tlow VERSION 0.1 LANGUAGES CXX)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "$ENV{HOME}/.local" CACHE PATH "" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
)

set(LLVM_ENABLE_PROJECTS "mlir" CACHE STRING "")
set(LLVM_TARGETS_TO_BUILD "X86;AArch64;NVPTX;AMDGPU" CACHE STRING "")
set(LLVM_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(LLVM_INCLUDE_TESTS OFF CACHE BOOL "" FORCE)

set(MLIR_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(MLIR_INCLUDE_TESTS OFF CACHE BOOL "" FORCE)

# MLIR
add_subdirectory(third_party/llvm-project/llvm)
find_package(MLIR REQUIRED CONFIG HINTS ${CMAKE_BINARY_DIR}/lib/cmake/mlir)

# match RTTI setting to what LLVM is built with
if(NOT LLVM_ENABLE_RTTI)
    if(MSVC)
        string(REGEX REPLACE "/GR" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /GR-")
    else()
        string(REGEX REPLACE "-frtti" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
    endif()
endif()

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${MLIR_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${CMAKE_BINARY_DIR}/include)

# ONNX Runtime
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(OnnxRuntime REQUIRED)

add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(tools)

add_custom_target(install-tlow
    COMMAND ${CMAKE_COMMAND} --install ${CMAKE_BINARY_DIR} --component tlow
    DEPENDS tlow-opt tlow
)