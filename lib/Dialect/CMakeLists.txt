add_library(tlowDialect TlowDialect.cpp)

add_dependencies(tlowDialect TlowDialectIncGen TlowOpsIncGen)
target_link_libraries(tlowDialect PRIVATE MLIRIR MLIRSupport)

target_include_directories(tlowDialect PRIVATE ${CMAKE_BINARY_DIR}/include)
target_include_directories(tlowDialect PRIVATE ${LLVM_INCLUDE_DIRS})
target_include_directories(tlowDialect PRIVATE ${MLIR_INCLUDE_DIRS})
target_include_directories(tlowDialect PUBLIC ${PROJECT_SOURCE_DIR}/include)