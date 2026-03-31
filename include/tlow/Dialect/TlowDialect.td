#ifndef TLOW_DIALECT_TD
#define TLOW_DIALECT_TD

include "mlir/IR/OpBase.td"

def Tlow_Dialect : Dialect {
    let name = "tlow";
    let cppNamespace = "::tlow";
}

#endif // TLOW_DIALECT_TD