//===- Ch0toyDialect.td - Ch0toy dialect -----------*- tablegen -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef CH0TOY_DIALECT
#define CH0TOY_DIALECT

include "mlir/IR/OpBase.td"

//===----------------------------------------------------------------------===//
// Ch0toy dialect definition.
//===----------------------------------------------------------------------===//

def Ch0toy_Dialect : Dialect {
    let name = "ch0toy";
    let summary = "A ch0toy out-of-tree MLIR dialect.";
    let description = [{
        This dialect is an example of an out-of-tree MLIR dialect designed to
        illustrate the basic setup required to develop MLIR-based tools without
        working inside of the LLVM source tree.
    }];
    let cppNamespace = "::mlir::ch0toy";

  let emitAccessorPrefix = kEmitAccessorPrefix_Prefixed;
}

//===----------------------------------------------------------------------===//
// Base ch0toy operation definition.
//===----------------------------------------------------------------------===//

class Ch0toy_Op<string mnemonic, list<Trait> traits = []> :
        Op<Ch0toy_Dialect, mnemonic, traits>;

#endif // CH0TOY_DIALECT
