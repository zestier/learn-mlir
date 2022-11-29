add_mlir_dialect_library(MLIRCh1toy
        AST.cpp
        Ch1toyDialect.cpp
        Ch1toyOps.cpp

        ADDITIONAL_HEADER_DIRS
        ${PROJECT_SOURCE_DIR}/include/Ch1toy

        DEPENDS
        MLIRCh1toyOpsIncGen

	LINK_LIBS PUBLIC
	MLIRIR
        MLIRInferTypeOpInterface
	)
