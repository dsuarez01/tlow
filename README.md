# tlow: an MLIR-based transformer compiler

As currently planned, tlow will be a JIT compiler that takes ONNX model subgraphs and lowers them to native code via MLIR. This project is integrated with ONNX Runtime as a custom runtime execution provider. Disclaimer: this is intended as an educational project.

Prerequisites:

- CMake 3.20+
- C++17 compiler
- Python (for MLIR TableGen)
- clang (optional, faster builds)
- ninja (optional, faster builds)
- ccache (optional, faster rebuilds)

To clone repo:

```bash
git clone --recurse-submodules https://github.com/dsuarez01/tlow.git
```

Minimal build:
```bash
mkdir build && cd build
cmake .. -DLLVM_ENABLE_PROJECTS="mlir" \
         -DLLVM_TARGETS_TO_BUILD="Native" \
         -DCMAKE_BUILD_TYPE=Release
cmake --build . --target tlow
```

Recommended (faster):
```bash
mkdir build && cd build
cmake .. -G Ninja \
         -DLLVM_ENABLE_PROJECTS="mlir" \
         -DLLVM_TARGETS_TO_BUILD="Native" \
         -DCMAKE_BUILD_TYPE=Release \
         -DCMAKE_C_COMPILER=clang \
         -DCMAKE_CXX_COMPILER=clang++ \
         -DCMAKE_C_COMPILER_LAUNCHER=ccache \
         -DCMAKE_CXX_COMPILER_LAUNCHER=ccache

# install tlow tools (run from build directory)
ninja install-tlow
```

> **Note:** clang, ninja, and ccache strongly recommended, since first build takes a significant amount of time (due to building LLVM/MLIR from source).

> **Note:** `Native` auto-targets your current architecture. Add `NVPTX` or `AMDGPU` to `LLVM_TARGETS_TO_BUILD` if you need GPU codegen support.