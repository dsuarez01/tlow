# define targets, point target to include dirs needed

add_library(tlowTransforms PatternRegistry.cpp)

target_link_libraries(tlowTransforms PRIVATE tlowDialect)

target_include_directories(tlowTransforms PRIVATE ${MLIR_INCLUDE_DIRS})
target_include_directories(tlowTransforms PUBLIC ${PROJECT_SOURCE_DIR}/include)