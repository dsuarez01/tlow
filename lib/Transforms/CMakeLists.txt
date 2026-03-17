# define targets, point target to include dirs needed

add_library(tlowTransforms PatternRegistry.cpp)

target_include_directories(tlowTransforms PUBLIC ${PROJECT_SOURCE_DIR}/include)