//===- Ch2toyDialect.cpp - Ch2toy dialect ---------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "toy/Ch2ToyDialect.h"
#include "toy/Ch2ToyOps.h"

using namespace mlir;
using namespace mlir::toy;

#include "toy/Ch2ToyOpsDialect.cpp.inc"

//===----------------------------------------------------------------------===//
// Ch2toy dialect.
//===----------------------------------------------------------------------===//

void ToyDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "toy/Ch2ToyOps.cpp.inc"
      >();
}
