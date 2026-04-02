# define targets, point target to include dirs needed

add_library(tlowTransforms PatternRegistry.cpp)

target_link_libraries(tlowTransforms PRIVATE tlowDialect)