// RUN: ch0-opt %s | ch0-opt | FileCheck %s

module {
    // CHECK-LABEL: func @bar()
    func.func @bar() {
        %0 = arith.constant 1 : i32
        // CHECK: %{{.*}} = ch0.foo %{{.*}} : i32
        %res = ch0.foo %0 : i32
        return
    }
}
