#ifndef TLOW_OPS_TD
#define TLOW_OPS_TD

include "mlir/IR/OpBase.td"
include "mlir/IR/BuiltinTypes.td"
include "mlir/Interfaces/SideEffectInterfaces.td"
include "TlowDialect.td"

class Tlow_Op<string mnemonic, list<Trait> traits = []> : Op<Tlow_Dialect, mnemonic, traits>;

def Tlow_MatMulOp : Tlow_Op<"matmul", [Pure]> {
    let summary = "Matrix multiplication";

    let arguments = (ins
        AnyTensor:$lhs,
        AnyTensor:$rhs
    );

    let results = (outs
        AnyTensor:$result
    );

    let assemblyFormat = [{
        $lhs `,` $rhs `:` type($lhs) `,` type($rhs) `->` type($result) attr-dict
    }];
}

#endif // TLOW_OPS_TD