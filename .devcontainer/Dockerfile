FROM ubuntu

# Throw in some coding tools
RUN apt-get update && apt-get -y install git cmake ninja-build

# Preinstall Clang and such because it supposedly builds MLIR faster
RUN apt-get update && apt-get -y install clang lld lldb

# Get the code for MLIR
ENV LLVM_SOURCE_DIR=/usr/local/src/llvm-project
ENV LLVM_BUILD_DIR=/usr/local/src/llvm-project/build
RUN git clone --depth 1 https://github.com/llvm/llvm-project.git $LLVM_SOURCE_DIR

# Build, install, and then delete unused files. Done in one step to avoid inflating cached images.
RUN                                                                                                \
   cmake                                                                                           \
      $LLVM_SOURCE_DIR/llvm                                                                        \
      -G Ninja                                                                                     \
      -B $LLVM_BUILD_DIR                                                                           \
      -DLLVM_ENABLE_PROJECTS="llvm;mlir"                                                           \
      -DCMAKE_BUILD_TYPE=RelWithDebInfo                                                            \
      -DLLVM_ENABLE_ASSERTIONS=ON                                                                  \
      -DCMAKE_C_COMPILER=clang                                                                     \
      -DCMAKE_CXX_COMPILER=clang++ -DLLVM_ENABLE_LLD=ON                                            \
      -DLLVM_INSTALL_UTILS=ON                                                                      \
   && cmake                                                                                        \
      --build $LLVM_BUILD_DIR                                                                      \
      --target install                                                                             \
   && find $LLVM_BUILD_DIR -type f -not \( -name 'llvm-lit' -or -name 'lit.site.cfg*' \) -delete   \
   && find $LLVM_SOURCE_DIR -type d -empty -delete

# Add in zsh because I like it better
RUN apt-get update && apt-get -y install zsh
RUN chsh -s `which zsh`
RUN echo "PROMPT='%~%# '" >> ~/.zshrc

CMD ["zsh"]