#include "mlir/IR/MLIRContext.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"

#include "tlow/Dialect/TlowDialect.h"
#include "tlow/Dialect/TlowOps.h"

int main(int argc, char* argv[]) {
    mlir::DialectRegistry registry;
    registry.insert<tlow::TlowDialect>();

    return mlir::asMainReturnCode(
        mlir::MlirOptMain(argc, argv, "tlow optimizer driver", registry)
    );
}