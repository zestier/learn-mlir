llvm_canonicalize_cmake_booleans(
        MLIR_ENABLE_BINDINGS_PYTHON
)

configure_lit_site_cfg(
        ${CMAKE_CURRENT_SOURCE_DIR}/lit.site.cfg.py.in
        ${CMAKE_CURRENT_BINARY_DIR}/lit.site.cfg.py
        MAIN_CONFIG
        ${CMAKE_CURRENT_SOURCE_DIR}/lit.cfg.py
)

set(CH0_TEST_DEPENDS
        FileCheck count not
        ch0-capi-test
        ch0-opt
        ch0-translate
        )
if(MLIR_ENABLE_BINDINGS_PYTHON)
  list(APPEND CH0_TEST_DEPENDS Ch0PythonModules)
endif()

add_lit_testsuite(check-ch0 "Running the ch0 regression tests"
        ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS ${CH0_TEST_DEPENDS}
        )
set_target_properties(check-ch0 PROPERTIES FOLDER "Tests")

add_lit_testsuites(CH0 ${CMAKE_CURRENT_SOURCE_DIR} DEPENDS ${CH0_TEST_DEPENDS})

add_subdirectory(CAPI)
