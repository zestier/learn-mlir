//===- Ch2toyDialect.cpp - Ch2toy dialect ---------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "toy/ToyDialect.h"
#include "toy/ToyOps.h"

using namespace mlir;
using namespace mlir::toy;

#include "toy/ToyOpsDialect.cpp.inc"

//===----------------------------------------------------------------------===//
// Ch2toy dialect.
//===----------------------------------------------------------------------===//

void ToyDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "toy/ToyOps.cpp.inc"
      >();
}
