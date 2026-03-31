# define targets, point target to include dirs needed

add_library(tlowFrontend ExecProvider.cpp)

target_link_libraries(tlowFrontend PRIVATE OnnxRuntime::OnnxRuntime)

target_include_directories(tlowFrontend PUBLIC ${PROJECT_SOURCE_DIR}/include)