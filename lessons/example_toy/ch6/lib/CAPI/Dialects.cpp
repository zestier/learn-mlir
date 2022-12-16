//===- Dialects.cpp - CAPI for dialects -----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "toy-c/Dialects.h"

#include "toy/Ch6ToyDialect.h"
#include "mlir/CAPI/Registration.h"

MLIR_DEFINE_CAPI_DIALECT_REGISTRATION(Toy, toy,
                                      mlir::toy::ToyDialect)
