//===- Ch0toyOps.cpp - Ch0toy dialect ops ---------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "Ch0toy/Ch0toyOps.h"
#include "Ch0toy/Ch0toyDialect.h"
#include "mlir/IR/OpImplementation.h"

#define GET_OP_CLASSES
#include "Ch0toy/Ch0toyOps.cpp.inc"
