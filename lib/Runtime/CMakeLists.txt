# define targets, point target to include dirs needed

add_library(tlowRuntime
    Graph.cpp
    Optimizers.cpp
    Tensor.cpp
)

target_include_directories(tlowRuntime PUBLIC ${PROJECT_SOURCE_DIR}/include)