add_library(tlowCodegenGPU Lowering.cpp)

target_include_directories(tlowCodegenGPU PRIVATE ${PROJECT_SOURCE_DIR}/include)