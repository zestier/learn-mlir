###############################################################################
# LLVM Source
###############################################################################
FROM alpine AS llvm-project-source
RUN apk --no-cache add tar
RUN                                                                                                \
   wget https://github.com/llvm/llvm-project/archive/refs/tags/llvmorg-16.0.1.tar.gz -O -          \
   | tar -xz --one-top-level=/out --strip-components=1

###############################################################################
# MLIR Base
###############################################################################
FROM ubuntu AS mlir-base

# Throw in some coding tools. Clang and Ninja supposedly build fastest
RUN apt-get update && apt-get install -y --no-install-recommends                                   \
   cmake clang lld lldb ninja-build                                                                \
   && rm -rf /var/lib/apt/lists/*

###############################################################################
# MLIR Build
###############################################################################
FROM mlir-base AS mlir-build

# Get the source code
ENV LLVM_BUILD_DIR=/out/build
ENV LLVM_INSTALL_DIR=/out/install
ENV LLVM_SOURCE_DIR=/in/source
COPY --from=llvm-project-source /out ${LLVM_SOURCE_DIR}

# CMake generation
RUN                                                                                                \
   cmake                                                                                           \
      ${LLVM_SOURCE_DIR}/llvm                                                                      \
      -G Ninja                                                                                     \
      -B /tmp/build                                                                                \
      -DCMAKE_BUILD_TYPE=Release                                                                   \
      -DCMAKE_INSTALL_PREFIX=${LLVM_INSTALL_DIR}                                                   \
      -DLLVM_ENABLE_PROJECTS="mlir"                                                                \
      -DLLVM_TARGETS_TO_BUILD="host"                                                               \
      -DLLVM_ENABLE_ASSERTIONS=ON                                                                  \
      -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DLLVM_ENABLE_LLD=ON                   \
      -DLLVM_INSTALL_UTILS=ON

# Copy over the non-install output we need. Conviently these files come from just the CMake generation.
RUN mkdir -p ${LLVM_BUILD_DIR}                                                                     \
   && cd /tmp/build                                                                                \
   && find . -type f \( -name 'llvm-lit' -or -name 'lit.site.cfg*' \) -exec cp --parents {} ${LLVM_BUILD_DIR} \;
   
# Fix a shebang to work with the way python is actually installed
RUN sed -i '1 s|^#!/usr/bin/python|#!/usr/bin/env python|g' ${LLVM_BUILD_DIR}/bin/llvm-lit

# CMake build.
# IMPORTANT: To avoid bloating the layer we delete when done. Because other steps may trigger copies
# out of the build directory we need to ensure this is at the end.
RUN cmake --build /tmp/build --target install                                                      \
   && rm -rf /tmp/build

###############################################################################
# Python dependency builder
###############################################################################
FROM ubuntu AS python-dep-builder

RUN apt-get update && apt-get -y install python3-venv
RUN python3 -m venv /out
ENV PATH=/out/bin:$PATH

# Actual deps
RUN pip3 install lit

###############################################################################
# Dev environment
###############################################################################
FROM mlir-base

# Optional dev tools
RUN apt-get update && apt-get install -y --no-install-recommends                                   \
   git zsh                                                                                         \
   && rm -rf /var/lib/apt/lists/*
RUN chsh -s `which zsh` && echo "PROMPT='%~%# '" >> ~/.zshrc

# Python dependencies
COPY --from=python-dep-builder /out /venv
ENV PATH=/venv/bin:$PATH

# LLVM/MLIR itself
ENV LLVM_BUILD_DIR=/llvm-project/build
COPY --from=mlir-build /out/build ${LLVM_BUILD_DIR}
COPY --from=mlir-build /out/install /usr/local

CMD ["zsh"]