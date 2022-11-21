get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)
set(LIBS
        ${dialect_libs}
        ${conversion_libs}
        MLIRArithDialect
        MLIROptLib
        MLIRCh1
        )
add_llvm_executable(ch1-opt ch1-opt.cpp)

llvm_update_compile_flags(ch1-opt)
target_link_libraries(ch1-opt PRIVATE ${LIBS})

mlir_check_all_link_libraries(ch1-opt)
