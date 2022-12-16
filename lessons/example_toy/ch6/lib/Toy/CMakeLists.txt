
set(LLVM_TARGET_DEFINITIONS ToyCombine.td)
mlir_tablegen(ToyCombine.inc -gen-rewriters)
add_public_tablegen_target(Ch6ToyCombineIncGen)

add_mlir_dialect_library(MLIRCh6Toy
        AST.cpp
        ToyDialect.cpp
        ToyOps.cpp
        Dialect.cpp
        MLIRGen.cpp
        LowerToAffineLoops.cpp
        LowerToLLVM.cpp
        ShapeInferencePass.cpp
        ToyCombine.cpp

        ADDITIONAL_HEADER_DIRS
        ${PROJECT_SOURCE_DIR}/include/toy

        DEPENDS
        MLIRCh6ToyOpsIncGen
        Ch6ToyCombineIncGen
        Ch6ToyShapeInferenceInterfaceIncGen

	LINK_LIBS PUBLIC
	MLIRIR
        MLIRInferTypeOpInterface
	)

target_include_directories(MLIRCh6Toy PRIVATE ${CMAKE_CURRENT_BINARY_DIR})