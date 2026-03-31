#ifndef TLOW_OPS_TD
#define TLOW_OPS_TD

include "mlir/IR/OpBase.td"
include "mlir/IR/BuiltinTypes.td"
include "mlir/Interfaces/SideEffectInterfaces.td"
include "TlowDialect.td"

class Tlow_Op<string mnemonic, list<Trait> traits = []> :
    Op<Tlow_Dialect, mnemonic, traits>;

#endif // TLOW_OPS_TD