#pragma once

#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/OpDefinition.h"
#include "mlir/IR/Operation.h"

#define GET_OP_CLASSES
#include "tlow/Dialect/TlowOps.h.inc"