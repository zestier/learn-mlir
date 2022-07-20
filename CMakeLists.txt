
cmake_minimum_required(VERSION 3.20)
project(learn-mlir)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

set(MLIR_DIR "/usr/local/lib/cmake/mlir" CACHE PATH "")
set(LLVM_EXTERNAL_LIT "$LLVM_BUILD_DIR/bin/llvm-lit" CACHE PATH "")

add_subdirectory("lessons")