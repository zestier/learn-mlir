//===- Ch1Dialect.td - Ch1 dialect -----------*- tablegen -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef CH1_DIALECT
#define CH1_DIALECT

include "mlir/IR/OpBase.td"

//===----------------------------------------------------------------------===//
// Ch1 dialect definition.
//===----------------------------------------------------------------------===//

def Ch1_Dialect : Dialect {
    let name = "ch1";
    let summary = "A ch1 out-of-tree MLIR dialect.";
    let description = [{
        This dialect is an example of an out-of-tree MLIR dialect designed to
        illustrate the basic setup required to develop MLIR-based tools without
        working inside of the LLVM source tree.
    }];
    let cppNamespace = "::mlir::ch1";

  let emitAccessorPrefix = kEmitAccessorPrefix_Prefixed;
}

//===----------------------------------------------------------------------===//
// Base ch1 operation definition.
//===----------------------------------------------------------------------===//

class Ch1_Op<string mnemonic, list<Trait> traits = []> :
        Op<Ch1_Dialect, mnemonic, traits>;

#endif // CH1_DIALECT
