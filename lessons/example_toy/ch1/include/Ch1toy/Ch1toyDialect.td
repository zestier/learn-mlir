//===- Ch1toyDialect.td - Ch1toy dialect -----------*- tablegen -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef CH1TOY_DIALECT
#define CH1TOY_DIALECT

include "mlir/IR/OpBase.td"

//===----------------------------------------------------------------------===//
// Ch1toy dialect definition.
//===----------------------------------------------------------------------===//

def Ch1toy_Dialect : Dialect {
    let name = "ch1toy";
    let summary = "A ch1toy out-of-tree MLIR dialect.";
    let description = [{
        This dialect is an example of an out-of-tree MLIR dialect designed to
        illustrate the basic setup required to develop MLIR-based tools without
        working inside of the LLVM source tree.
    }];
    let cppNamespace = "::mlir::ch1toy";

  let emitAccessorPrefix = kEmitAccessorPrefix_Prefixed;
}

//===----------------------------------------------------------------------===//
// Base ch1toy operation definition.
//===----------------------------------------------------------------------===//

class Ch1toy_Op<string mnemonic, list<Trait> traits = []> :
        Op<Ch1toy_Dialect, mnemonic, traits>;

#endif // CH1TOY_DIALECT
