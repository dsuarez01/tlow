# define targets, point target to include dirs needed

add_library(tlowImporter OnnxImporter.cpp)

target_link_libraries(tlowImporter PRIVATE onnx)

target_include_directories(tlowImporter PUBLIC ${PROJECT_SOURCE_DIR}/include)