//===- Ch0Dialect.td - Ch0 dialect -----------*- tablegen -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef CH0_DIALECT
#define CH0_DIALECT

include "mlir/IR/OpBase.td"

//===----------------------------------------------------------------------===//
// Ch0 dialect definition.
//===----------------------------------------------------------------------===//

def Ch0_Dialect : Dialect {
    let name = "ch0";
    let summary = "A ch0 out-of-tree MLIR dialect.";
    let description = [{
        This dialect is an example of an out-of-tree MLIR dialect designed to
        illustrate the basic setup required to develop MLIR-based tools without
        working inside of the LLVM source tree.
    }];
    let cppNamespace = "::mlir::ch0";

  let emitAccessorPrefix = kEmitAccessorPrefix_Prefixed;
}

//===----------------------------------------------------------------------===//
// Base ch0 operation definition.
//===----------------------------------------------------------------------===//

class Ch0_Op<string mnemonic, list<Trait> traits = []> :
        Op<Ch0_Dialect, mnemonic, traits>;

#endif // CH0_DIALECT
