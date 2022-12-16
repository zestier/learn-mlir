
set(LLVM_TARGET_DEFINITIONS ToyCombine.td)
mlir_tablegen(ToyCombine.inc -gen-rewriters)
add_public_tablegen_target(Ch7ToyCombineIncGen)

add_mlir_dialect_library(MLIRCh7Toy
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
        MLIRCh7ToyOpsIncGen
        Ch7ToyCombineIncGen
        Ch7ToyShapeInferenceInterfaceIncGen

	LINK_LIBS PUBLIC
	MLIRIR
        MLIRInferTypeOpInterface
	)

target_include_directories(MLIRCh7Toy PRIVATE ${CMAKE_CURRENT_BINARY_DIR})