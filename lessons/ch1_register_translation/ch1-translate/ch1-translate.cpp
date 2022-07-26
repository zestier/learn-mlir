//===- ch1-translate.cpp ---------------------------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This is a command line utility that translates a file from/to MLIR using one
// of the registered translations.
//
//===----------------------------------------------------------------------===//

#include "llvm/Support/SourceMgr.h"
#include "mlir/InitAllTranslations.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/Support/LogicalResult.h"
#include "mlir/Tools/mlir-translate/MlirTranslateMain.h"
#include "mlir/Tools/mlir-translate/Translation.h"

#include "Ch1/Ch1Dialect.h"

namespace {
  mlir::OwningOpRef<mlir::ModuleOp> translateToModule(
      llvm::SourceMgr&    sourceMgr,
      mlir::MLIRContext*  context
  ) {
    auto& memoryBuffer = *sourceMgr.getMemoryBuffer(sourceMgr.getMainFileID());
    auto module = mlir::ModuleOp::create(
      mlir::FileLineColLoc::get(
        context,
        memoryBuffer.getBufferIdentifier(),
        /*line=*/0,
        /*column=*/0
      )
    );

    return module;
  }

  void registerFromCh1Translation() {
    mlir::TranslateToMLIRRegistration fromCh1(
      "import-ch1", [](llvm::SourceMgr& sourceMgr, mlir::MLIRContext* context) {
        return translateToModule(sourceMgr, context);
      }
    );
  }
}

int main(int argc, char** argv) {
  mlir::registerAllTranslations();
  registerFromCh1Translation();

  return failed(
      mlir::mlirTranslateMain(argc, argv, "ch1-translate")
  );
}
