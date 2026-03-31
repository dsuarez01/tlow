include_directories(${MLIR_INCLUDE_DIRS})
include_directories(${LLVM_INCLUDE_DIRS})

set(LLVM_TARGET_DEFINITIONS TlowDialect.td)
mlir_tablegen(TlowDialect.h.inc -gen-dialect-decls -dialect tlow)
mlir_tablegen(TlowDialect.cpp.inc -gen-dialect-defs -dialect tlow)
add_public_tablegen_target(TlowDialectIncGen)

set(LLVM_TARGET_DEFINITIONS TlowOps.td)
mlir_tablegen(TlowOps.h.inc -gen-op-decls -dialect tlow)
mlir_tablegen(TlowOps.cpp.inc -gen-op-defs -dialect tlow)
add_public_tablegen_target(TlowOpsIncGen)