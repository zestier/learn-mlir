add_mlir_dialect_library(MLIRCh2toy
        AST.cpp
        ToyDialect.cpp
        ToyOps.cpp
        Dialect.cpp
        MLIRGen.cpp

        ADDITIONAL_HEADER_DIRS
        ${PROJECT_SOURCE_DIR}/include/toy

        DEPENDS
        MLIRToyOpsIncGen

	LINK_LIBS PUBLIC
	MLIRIR
        MLIRInferTypeOpInterface
	)
