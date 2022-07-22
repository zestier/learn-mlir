# An out-of-tree MLIR dialect

This example will show how to register a basic translation. It will do nearly nothing aside from providing the scaffolding. See ch1-translate.

This is an example of an out-of-tree [MLIR](https://mlir.llvm.org/) dialect along with a ch1 `opt`-like tool to operate on that dialect.

## Building

This setup assumes that you have built LLVM and MLIR in `$BUILD_DIR` and installed them to `$PREFIX`. To build and launch the tests, run
```sh
mkdir build && cd build
cmake -G Ninja .. -DMLIR_DIR=$PREFIX/lib/cmake/mlir -DLLVM_EXTERNAL_LIT=$BUILD_DIR/bin/llvm-lit
cmake --build . --target check-ch1
```
To build the documentation from the TableGen description of the dialect operations, run
```sh
cmake --build . --target mlir-doc
```
**Note**: Make sure to pass `-DLLVM_INSTALL_UTILS=ON` when building LLVM with CMake in order to install `FileCheck` to the chosen installation prefix.

