# Here we create a single aggregate shared library with the parts of the CAPI
# that we want to bundle together. Then we link a simple C executable
# against it to demonstrate that it does have the fully self contained
# core MLIR library and our own ch0 dialect.
add_mlir_aggregate(Ch0CAPITestLib
  SHARED
  EMBED_LIBS
  MLIRCAPIIR
  # TODO: Remove this in favor of showing fine grained dialect registration
  # (once available).
  MLIRCAPIRegisterEverything
  Ch0CAPI
)

add_llvm_executable(ch0-capi-test
  ch0-capi-test.c
)
llvm_update_compile_flags(ch0-capi-test)
target_link_libraries(ch0-capi-test
  PRIVATE Ch0CAPITestLib)
