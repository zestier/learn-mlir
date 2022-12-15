
set(LLVM_TARGET_DEFINITIONS ToyCombine.td)
mlir_tablegen(ToyCombine.inc -gen-rewriters)
add_public_tablegen_target(Ch5ToyCombineIncGen)

add_mlir_dialect_library(MLIRCh5Toy
        AST.cpp
        ToyDialect.cpp
        ToyOps.cpp
        Dialect.cpp
        MLIRGen.cpp
        LowerToAffineLoops.cpp
        ShapeInferencePass.cpp
        ToyCombine.cpp

        ADDITIONAL_HEADER_DIRS
        ${PROJECT_SOURCE_DIR}/include/toy

        DEPENDS
        MLIRCh5ToyOpsIncGen
        Ch5ToyCombineIncGen
        Ch5ToyShapeInferenceInterfaceIncGen

	LINK_LIBS PUBLIC
	MLIRIR
        MLIRInferTypeOpInterface
	)

target_include_directories(MLIRCh5Toy PRIVATE ${CMAKE_CURRENT_BINARY_DIR})