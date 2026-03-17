# tlow: lowering transformer-style computation graphs through MLIR

As currently planned, tlow will be a minimal AOT compiler that ingests ONNX models and lowers them to native code for CPU targets via MLIR. GPU and custom accelerator targets will be eventually added in as an experimental feature. This is intended as an educational project.

Prerequisites:

- CMake 3.20+
- C++ 17 compiler
- Python (for MLIR TableGen) 

To clone repo:

```bash
git clone --recurse-submodules https://github.com/dsuarez01/tlow.git
```

To build:

```bash
mkdir build && cd build
cmake .. -DLLVM_ENABLE_PROJECTS="mlir" \
         -DLLVM_TARGETS_TO_BUILD="X86;AArch64;NVPTX;AMDGPU" \
         -DCMAKE_BUILD_TYPE=Release
cmake --build . --target tlow
```