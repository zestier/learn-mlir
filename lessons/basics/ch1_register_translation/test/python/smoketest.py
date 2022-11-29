# RUN: %python %s | FileCheck %s

from mlir_ch1.ir import *
from mlir_ch1.dialects import (
  builtin as builtin_d,
  ch1 as ch1_d
)

with Context():
  ch1_d.register_dialect()
  module = Module.parse("""
    %0 = arith.constant 2 : i32
    %1 = ch1.foo %0 : i32
    """)
  # CHECK: %[[C:.*]] = arith.constant 2 : i32
  # CHECK: ch1.foo %[[C]] : i32
  print(str(module))
