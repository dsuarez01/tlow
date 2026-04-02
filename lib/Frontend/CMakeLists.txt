# define targets, point target to include dirs needed

add_library(tlowFrontend ExecProvider.cpp)

target_link_libraries(tlowFrontend PRIVATE OnnxRuntime::OnnxRuntime)