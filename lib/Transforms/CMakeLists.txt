mlir_library(tlowTransforms
  PatternRegistry.cpp

  LINK_LIBS PUBLIC
    tlowDialect
    MLIRLinalg
    MLIRLinalgTransforms
    MLIRFuncDialect
    MLIRTensor
    MLIRTransforms
)

target_link_libraries(tlowTransforms PRIVATE tlowDialect)