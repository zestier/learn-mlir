
set(LLVM_TARGET_DEFINITIONS ToyCombine.td)
mlir_tablegen(ToyCombine.inc -gen-rewriters)
add_public_tablegen_target(Ch4ToyCombineIncGen)

add_mlir_dialect_library(MLIRCh4toy
        AST.cpp
        ToyDialect.cpp
        ToyOps.cpp
        Dialect.cpp
        MLIRGen.cpp
        ShapeInferencePass.cpp
        ToyCombine.cpp

        ADDITIONAL_HEADER_DIRS
        ${PROJECT_SOURCE_DIR}/include/toy

        DEPENDS
        MLIRCh4ToyOpsIncGen
        Ch4ToyCombineIncGen
        ToyCh4ShapeInferenceInterfaceIncGen

	LINK_LIBS PUBLIC
	MLIRIR
        MLIRInferTypeOpInterface
	)

target_include_directories(MLIRCh4toy PRIVATE ${CMAKE_CURRENT_BINARY_DIR})