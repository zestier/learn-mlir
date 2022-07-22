//===- Ch1Dialect.cpp - Ch1 dialect ---------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "Ch1/Ch1Dialect.h"
#include "Ch1/Ch1Ops.h"

using namespace mlir;
using namespace mlir::ch1;

#include "Ch1/Ch1OpsDialect.cpp.inc"

//===----------------------------------------------------------------------===//
// Ch1 dialect.
//===----------------------------------------------------------------------===//

void Ch1Dialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "Ch1/Ch1Ops.cpp.inc"
      >();
}
