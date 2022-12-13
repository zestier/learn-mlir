
set(LLVM_TARGET_DEFINITIONS Ch3ToyCombine.td)
mlir_tablegen(Ch3ToyCombine.inc -gen-rewriters)
add_public_tablegen_target(Ch3ToyCombineIncGen)

add_mlir_dialect_library(MLIRCh3toy
        AST.cpp
        ToyDialect.cpp
        ToyOps.cpp
        Dialect.cpp
        MLIRGen.cpp
        Ch3ToyCombine.cpp

        ADDITIONAL_HEADER_DIRS
        ${PROJECT_SOURCE_DIR}/include/toy

        DEPENDS
        MLIRCh3ToyOpsIncGen
        Ch3ToyCombineIncGen

	LINK_LIBS PUBLIC
	MLIRIR
        MLIRInferTypeOpInterface
	)

target_include_directories(MLIRCh3toy PRIVATE ${CMAKE_CURRENT_BINARY_DIR})