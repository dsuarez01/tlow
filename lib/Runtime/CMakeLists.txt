# define targets, point target to include dirs needed

add_library(tlowRuntime
    Allocator.cpp
    Graph.cpp
    Tensor.cpp
)

target_include_directories(tlowRuntime PUBLIC ${PROJECT_SOURCE_DIR}/include)