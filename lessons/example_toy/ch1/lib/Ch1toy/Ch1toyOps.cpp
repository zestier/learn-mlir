//===- Ch1toyOps.cpp - Ch1toy dialect ops ---------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "Ch1toy/Ch1toyOps.h"
#include "Ch1toy/Ch1toyDialect.h"
#include "mlir/IR/OpImplementation.h"

#define GET_OP_CLASSES
#include "Ch1toy/Ch1toyOps.cpp.inc"
