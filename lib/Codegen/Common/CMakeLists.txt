
add_library(tlowCodegenCommon Lowering.cpp)

target_include_directories(tlowCodegenCommon PRIVATE ${PROJECT_SOURCE_DIR}/include)
