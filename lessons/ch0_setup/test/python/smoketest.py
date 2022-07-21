# RUN: %python %s | FileCheck %s

from mlir_ch0.ir import *
from mlir_ch0.dialects import (
  builtin as builtin_d,
  ch0 as ch0_d
)

with Context():
  ch0_d.register_dialect()
  module = Module.parse("""
    %0 = arith.constant 2 : i32
    %1 = ch0.foo %0 : i32
    """)
  # CHECK: %[[C:.*]] = arith.constant 2 : i32
  # CHECK: ch0.foo %[[C]] : i32
  print(str(module))
