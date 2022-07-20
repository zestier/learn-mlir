include(AddMLIRPython)

# Specifies that all MLIR packages are co-located under the `mlir_ch1`
# top level package (the API has been embedded in a relocatable way).
# TODO: Add an upstream cmake param for this vs having a global here.
add_compile_definitions("MLIR_PYTHON_PACKAGE_PREFIX=mlir_ch1.")


################################################################################
# Sources
################################################################################

declare_mlir_python_sources(Ch1PythonSources)

declare_mlir_dialect_python_bindings(
  ADD_TO_PARENT Ch1PythonSources
  ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/mlir_ch1"
  TD_FILE dialects/Ch1Ops.td
  SOURCES
    dialects/ch1.py
  DIALECT_NAME ch1)

declare_mlir_python_extension(Ch1PythonSources.Extension
  MODULE_NAME _ch1Dialects
  ADD_TO_PARENT Ch1PythonSources
  SOURCES
    Ch1Extension.cpp
  EMBED_CAPI_LINK_LIBS
    Ch1CAPI
)

################################################################################
# Common CAPI
################################################################################

add_mlir_python_common_capi_library(Ch1PythonCAPI
  INSTALL_COMPONENT Ch1PythonModules
  INSTALL_DESTINATION python_packages/ch1/mlir_ch1/_mlir_libs
  OUTPUT_DIRECTORY "${MLIR_BINARY_DIR}/python_packages/ch1/mlir_ch1/_mlir_libs"
  RELATIVE_INSTALL_ROOT "../../../.."
  DECLARED_SOURCES
    Ch1PythonSources
    MLIRPythonSources.Core
)

################################################################################
# Instantiation of all Python modules
################################################################################

add_mlir_python_modules(Ch1PythonModules
  ROOT_PREFIX "${MLIR_BINARY_DIR}/python_packages/ch1/mlir_ch1"
  INSTALL_PREFIX "python_packages/ch1/mlir_ch1"
  DECLARED_SOURCES
    Ch1PythonSources
    MLIRPythonSources
  COMMON_CAPI_LINK_LIBS
    Ch1PythonCAPI
  )
