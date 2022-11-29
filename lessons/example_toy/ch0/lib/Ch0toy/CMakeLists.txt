add_mlir_dialect_library(MLIRCh0toy
        AST.cpp
        Ch0toyDialect.cpp
        Ch0toyOps.cpp

        ADDITIONAL_HEADER_DIRS
        ${PROJECT_SOURCE_DIR}/include/Ch0toy

        DEPENDS
        MLIRCh0toyOpsIncGen

	LINK_LIBS PUBLIC
	MLIRIR
        MLIRInferTypeOpInterface
	)
