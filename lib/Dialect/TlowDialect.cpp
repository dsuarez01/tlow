#include "tlow/Dialect/TlowDialect.h"
#include "tlow/Dialect/TlowOps.h"

#define GET_DIALECT_DEFS
#include "tlow/Dialect/TlowDialect.cpp.inc"

void tlow::TlowDialect::initialize() {
    addOperations<
        #define GET_OP_LIST
        #include "tlow/Dialect/TlowOps.cpp.inc"
    >();
}