//===- Ch1toyDialect.cpp - Ch1toy dialect ---------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "Ch1toy/Ch1toyDialect.h"
#include "Ch1toy/Ch1toyOps.h"

using namespace mlir;
using namespace mlir::ch1toy;

#include "Ch1toy/Ch1toyOpsDialect.cpp.inc"

//===----------------------------------------------------------------------===//
// Ch1toy dialect.
//===----------------------------------------------------------------------===//

void Ch1toyDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "Ch1toy/Ch1toyOps.cpp.inc"
      >();
}
