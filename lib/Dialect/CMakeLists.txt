add_mlir_library(tlowDialect
    TlowDialect.cpp
    TlowOps.cpp

    ADDITIONAL_HEADER_DIRS
    ${PROJECT_SOURCE_DIR}/include

    DEPENDS
    TlowDialectIncGen
    TlowOpsIncGen

    LINK_COMPONENTS
    Core

    LINK_LIBS PUBLIC
    MLIRIR
    MLIRSupport
)