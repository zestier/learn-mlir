get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)
set(LIBS
        ${dialect_libs}
        ${conversion_libs}
        MLIRArithmeticDialect
        MLIROptLib
        MLIRCh0
        )
add_llvm_executable(ch0-opt ch0-opt.cpp)

llvm_update_compile_flags(ch0-opt)
target_link_libraries(ch0-opt PRIVATE ${LIBS})

mlir_check_all_link_libraries(ch0-opt)
