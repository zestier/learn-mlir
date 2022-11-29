// RUN: ch1-opt %s | ch1-opt | FileCheck %s

module {
    // CHECK-LABEL: func @bar()
    func.func @bar() {
        %0 = arith.constant 1 : i32
        // CHECK: %{{.*}} = ch1.foo %{{.*}} : i32
        %res = ch1.foo %0 : i32
        return
    }
}
