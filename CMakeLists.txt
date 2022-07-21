
cmake_minimum_required(VERSION 3.20)
project(learn-mlir)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

set(MLIR_DIR "/usr/local/lib/cmake/mlir" CACHE PATH "")
set(LLVM_EXTERNAL_LIT "$ENV{LLVM_BUILD_DIR}/bin/llvm-lit" CACHE PATH "")

# We aren't actually interested in policy issues in these generated lessons
set(CMAKE_POLICY_DEFAULT_CMP0116 OLD)
add_subdirectory("lessons")