//===- Ch0toyDialect.cpp - Ch0toy dialect ---------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "Ch0toy/Ch0toyDialect.h"
#include "Ch0toy/Ch0toyOps.h"

using namespace mlir;
using namespace mlir::ch0toy;

#include "Ch0toy/Ch0toyOpsDialect.cpp.inc"

//===----------------------------------------------------------------------===//
// Ch0toy dialect.
//===----------------------------------------------------------------------===//

void Ch0toyDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "Ch0toy/Ch0toyOps.cpp.inc"
      >();
}
