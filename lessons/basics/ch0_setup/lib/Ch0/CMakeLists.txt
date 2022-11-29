add_mlir_dialect_library(MLIRCh0
        Ch0Dialect.cpp
        Ch0Ops.cpp

        ADDITIONAL_HEADER_DIRS
        ${PROJECT_SOURCE_DIR}/include/Ch0

        DEPENDS
        MLIRCh0OpsIncGen

	LINK_LIBS PUBLIC
	MLIRIR
        MLIRInferTypeOpInterface
	)
