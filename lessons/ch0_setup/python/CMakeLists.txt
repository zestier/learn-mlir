include(AddMLIRPython)

# Specifies that all MLIR packages are co-located under the `mlir_ch0`
# top level package (the API has been embedded in a relocatable way).
# TODO: Add an upstream cmake param for this vs having a global here.
add_compile_definitions("MLIR_PYTHON_PACKAGE_PREFIX=mlir_ch0.")


################################################################################
# Sources
################################################################################

declare_mlir_python_sources(Ch0PythonSources)

declare_mlir_dialect_python_bindings(
  ADD_TO_PARENT Ch0PythonSources
  ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/mlir_ch0"
  TD_FILE dialects/Ch0Ops.td
  SOURCES
    dialects/ch0.py
  DIALECT_NAME ch0)

declare_mlir_python_extension(Ch0PythonSources.Extension
  MODULE_NAME _ch0Dialects
  ADD_TO_PARENT Ch0PythonSources
  SOURCES
    Ch0Extension.cpp
  EMBED_CAPI_LINK_LIBS
    Ch0CAPI
)

################################################################################
# Common CAPI
################################################################################

add_mlir_python_common_capi_library(Ch0PythonCAPI
  INSTALL_COMPONENT Ch0PythonModules
  INSTALL_DESTINATION python_packages/ch0/mlir_ch0/_mlir_libs
  OUTPUT_DIRECTORY "${MLIR_BINARY_DIR}/python_packages/ch0/mlir_ch0/_mlir_libs"
  RELATIVE_INSTALL_ROOT "../../../.."
  DECLARED_SOURCES
    Ch0PythonSources
    MLIRPythonSources.Core
)

################################################################################
# Instantiation of all Python modules
################################################################################

add_mlir_python_modules(Ch0PythonModules
  ROOT_PREFIX "${MLIR_BINARY_DIR}/python_packages/ch0/mlir_ch0"
  INSTALL_PREFIX "python_packages/ch0/mlir_ch0"
  DECLARED_SOURCES
    Ch0PythonSources
    MLIRPythonSources
  COMMON_CAPI_LINK_LIBS
    Ch0PythonCAPI
  )
