add_mlir_dialect(Ch6ToyOps toy)
add_mlir_doc(Ch6ToyDialect Ch6ToyDialect toy/ -gen-dialect-doc)
add_mlir_doc(Ch6ToyOps Ch6ToyOps toy/ -gen-op-doc)

# Most dialects should use add_mlir_interfaces(). This was just copied from an odd sample
set(LLVM_TARGET_DEFINITIONS ShapeInferenceInterface.td)
mlir_tablegen(ShapeInferenceOpInterfaces.h.inc -gen-op-interface-decls)
mlir_tablegen(ShapeInferenceOpInterfaces.cpp.inc -gen-op-interface-defs)
add_public_tablegen_target(Ch6ToyShapeInferenceInterfaceIncGen)