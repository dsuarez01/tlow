add_executable(tlow-opt
    main.cpp
)

target_include_directories(tlow-opt PRIVATE
    ${MLIR_INCLUDE_DIRS}
    ${LLVM_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}/include
)

target_link_libraries(tlow-opt PRIVATE
    MLIROptLib
    MLIRParser
    MLIRIR
    MLIRDialect
    MLIRSupport
    tlowDialect
    tlowCodegen
    tlowTransforms
)