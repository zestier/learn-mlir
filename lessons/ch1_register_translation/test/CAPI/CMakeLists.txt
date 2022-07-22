# Here we create a single aggregate shared library with the parts of the CAPI
# that we want to bundle together. Then we link a simple C executable
# against it to demonstrate that it does have the fully self contained
# core MLIR library and our own ch1 dialect.
add_mlir_aggregate(Ch1CAPITestLib
  SHARED
  EMBED_LIBS
  MLIRCAPIIR
  MLIRCAPIRegistration
  Ch1CAPI
)

add_llvm_executable(ch1-capi-test
  ch1-capi-test.c
)
llvm_update_compile_flags(ch1-capi-test)
target_link_libraries(ch1-capi-test
  PRIVATE Ch1CAPITestLib)
