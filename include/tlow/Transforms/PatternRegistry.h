#pragma once
// collection of rewrite patterns

#include "mlir/Pass/Pass.h"
#include <memory>

namespace tlow {

std::unique_ptr<mlir::Pass> createLowerTlowToLinalgPass();

} // namespace tlow