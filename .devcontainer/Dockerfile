FROM ubuntu

# Throw in some coding tools. Clang and Ninja supposedly build fastest
RUN apt-get update && apt-get -y install cmake git wget clang lld lldb ninja-build

# Prepare the environment for the pull
ENV LLVM_SOURCE_DIR=/llvm-project
ENV LLVM_BUILD_DIR=/llvm-project/build

# Fix the relevant code. Pulling a tagged tar just happens to be fast and stable.
RUN                                                                                                \
   wget -c https://github.com/llvm/llvm-project/archive/refs/tags/llvmorg-15.0.5.tar.gz -O -       \
   | tar -xz --one-top-level=$LLVM_SOURCE_DIR --strip-components=1

# Build, install, and then delete unused files. Done in one step to avoid inflating cached images.
RUN                                                                                                \
   cmake                                                                                           \
      $LLVM_SOURCE_DIR/llvm                                                                        \
      -G Ninja                                                                                     \
      -B $LLVM_BUILD_DIR                                                                           \
      -DLLVM_ENABLE_PROJECTS="llvm;mlir"                                                           \
      -DLLVM_TARGETS_TO_BUILD="host"                                                               \
      -DCMAKE_BUILD_TYPE=Release                                                                   \
      -DLLVM_ENABLE_ASSERTIONS=ON                                                                  \
      -DCMAKE_C_COMPILER=clang                                                                     \
      -DCMAKE_CXX_COMPILER=clang++ -DLLVM_ENABLE_LLD=ON                                            \
      -DLLVM_INSTALL_UTILS=ON                                                                      \
   && cmake                                                                                        \
      --build $LLVM_BUILD_DIR                                                                      \
      --target install                                                                             \
   && find $LLVM_BUILD_DIR -type f -not \( -name 'llvm-lit' -or -name 'lit.site.cfg*' \) -delete   \
   && find $LLVM_BUILD_DIR -type d -empty -delete

# Add in zsh because I like it better
RUN apt-get update && apt-get -y install zsh
RUN chsh -s `which zsh` && echo "PROMPT='%~%# '" >> ~/.zshrc

CMD ["zsh"]