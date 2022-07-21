//===- Ch0Dialect.cpp - Ch0 dialect ---------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "Ch0/Ch0Dialect.h"
#include "Ch0/Ch0Ops.h"

using namespace mlir;
using namespace mlir::ch0;

#include "Ch0/Ch0OpsDialect.cpp.inc"

//===----------------------------------------------------------------------===//
// Ch0 dialect.
//===----------------------------------------------------------------------===//

void Ch0Dialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "Ch0/Ch0Ops.cpp.inc"
      >();
}
