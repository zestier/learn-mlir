add_mlir_dialect_library(MLIRCh1
        Ch1Dialect.cpp
        Ch1Ops.cpp

        ADDITIONAL_HEADER_DIRS
        ${PROJECT_SOURCE_DIR}/include/Ch1

        DEPENDS
        MLIRCh1OpsIncGen

	LINK_LIBS PUBLIC
	MLIRIR
        MLIRInferTypeOpInterface
	)
